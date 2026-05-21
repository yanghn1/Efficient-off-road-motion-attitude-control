nx = 3;
nu = 2;

T = 50;
N = 1800;
rho = 3;
noise = diag([0.3 0.7]);

%% start value
x0 = [0;2;0];
u = randn(nu,T)*0;

%% data
data.f = @f;
data.h = @h;
data.getcost = @getcost;

data.T = T;
data.N = N;
data.nx = nx;
data.nu = nu;
data.rho = rho;
data.noise = noise;

% plot
data.getplot = @getplot;
data.showresult = @showresult;

figure(1); 
xMin=0;
xMax=500;
numObstacles=15;
hold on
xObs=[18-135	25-135	40-135	51-135	68-60	86	91	100	104	140	145	157	174	186	196]'+140;
yObs=[2.95261642174925	4.35982577862329	4.62406906911814	3.85379687613981	2.70000000000000	-2.40000000000000	8.30000000000000	-1.00000000000000	-0.9000000000000000	2.5	2.5	-3.30000000000000	3.70000000000000	-5.80000000000000	3.70000000000000]';
rObs=[1.15261657874791	2.55983758448023	1.87681846288179	2.44693035566188	2.95597902399321	2.07699174082087	2.00224092731988	1.14410226671952	1.53687796020374	1.99976500165112	2.35845999224188	2.60747807220875	1.76188226629708	1.13187269381181	1.17629119861599]';
theta = linspace(0, 2 * pi, 120);
for i = 1:numObstacles
    xCircle = xObs(i) + rObs(i) * cos(theta);
    yCircle = yObs(i) + rObs(i) * sin(theta);

    fill(xCircle, yCircle, [0.85 0.25 0.20], ...
        'FaceAlpha', 0.45, ...
        'EdgeColor', [0.55 0.05 0.03], ...
        'LineWidth', 1.2);

    text(xObs(i), yObs(i), sprintf('%d', i), ...
        'HorizontalAlignment', 'center', ...
        'VerticalAlignment', 'middle', ...
        'FontSize', 8, ...
        'FontWeight', 'bold');
end
xlim([xMin xMax]);
ylim([-5 9]);

hold on;
% ax=gca; ax.FontSize = 18;
% 
data.plotdisp = line(0,0);
data.plotdisp1 = line(0,0);

%% functions
function y = f(x,u)

    dt = 0.07;
    y = [x(1,:) + dt*u(1,:).*cos(x(3,:)); 
         x(2,:) + dt*u(1,:).*sin(x(3,:));
         x(3,:) + dt*u(2,:)];
end
function y = h(u)

    y = [max(min(u(1,:),18),17);
         max(min(u(2,:),0.5),-0.5)];
end
function y = getcost(x0,U,data)
    
    N = data.N;
    T = data.T;
    f = data.f;
    h = data.h;

    x = repmat(x0,N);
    cost = zeros(1,N);
    for t=1:T
        u = U(:,:,t);
        x = f(x,h(u));
        cost = cost + l(x,u); 
    end
    y = cost + lf(x,u);

    function y = l(x,u)
        y = 1*vecnorm(u(1,:) - [0],'inf')+ 10000*sum(u(2,:).^2) + 1e-1*vecnorm(x(1:2,:) - [600;0],'inf')+ 1e8*collisioncheck(x(1:2,:));
    end

    function y = lf(x,u)
        y = vecnorm(x - [600;0;0],'inf')*800;
    end

    function y = collisioncheck(x)

%% 障碍物位置
        xObs=[18-135	25-135	40-135	51-135	68-60	86	91	100	104	140	145	157	174	186	196]'+140;
        yObs=[2.65261642174925	4.05982577862329	4.62406906911814	3.85379687613981	2.40000000000000	-2.10000000000000	8.30000000000000	-1.00000000000000	-0.600000000000000	2.2	2.2	-3.30000000000000	3.70000000000000	-5.80000000000000	3.70000000000000]';
        rObs=[1.15261657874791	2.55983758448023	1.87681846288179	2.44693035566188	2.95597902399321	2.07699174082087	2.00224092731988	1.14410226671952	1.53687796020374	1.99976500165112	2.35845999224188	2.60747807220875	1.76188226629708	1.13187269381181	0.87629119861599]';

        y = 0;

        yy = x(2,:) > 5 | x(2,:) < -5;
        y = y | (yy);
        for i=1:length(xObs)
                yx = (x(1,:) - xObs(i)).^2 + (x(2,:) - yObs(i)).^2 < rObs(i)^2;
                y = y | yx;
        end
    end
end

% function getplot(x,u,data)
%     set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
%         'Marker','.','LineStyle','none','Color','k','MarkerSize',10);
%     drawnow;
% end

function getplot(i,x,u,data)
    
    if i == 0
    set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
        'Marker','.','LineStyle','none','Color','k','MarkerSize',5);
    else
    set(data.plotdisp1,'XData',x(1,:),'Ydata',x(2,:),...
    'Marker','.','LineStyle','none','Color','c','MarkerSize',15);
    end
    drawnow;
end

