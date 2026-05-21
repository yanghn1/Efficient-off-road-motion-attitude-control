nz = 3; % [cx,cy,r]

T = 50;
N = 1000;
rho = 0.001;
noise = diag([0.08 0.08 0.05]);
rmax = 1.6;

%% data
data1.hz = @hz;
data1.getcost = @getcost;
data1.rmax = rmax;

data1.T = T;
data1.N = N;
data1.nz = nz;
data1.rho = rho;
data1.noise = noise;

%% functions
function y = hz(z,p,rmax) 

    % z: (nz x N) x T
    % p: 2 x T

    r = max(min(z(3,:,:),rmax),0);
    y(3,:,:) = r;
    x = z(1:2,:,:) - reshape(p,2,1,[]);

    xmag = vecnorm(x,2);
    idx = find(xmag > r);
    x(:,idx) = x(:,idx)./xmag(:,idx).*r(:,idx);
    y(1:2,:,:) = x + reshape(p,2,1,[]);
end
function y = getcost(z,p,data)

    % z: (nz x N) x T
    % p: 2 x T
    
    hz = data.hz;
    rmax = data.rmax;

    z = hz(z,p,rmax);
    y = l(z,p); 

    function y = l(z,p)
        x = z(1:2,:,:) - reshape(p,2,1,[]);
        y = -18*z(3,:,:) + 20*vecnorm(x,2) + 1e8*collisioncheck(z);
    end
    function y = collisioncheck(z)

        y = 0;
%% 障碍物位置
        xObs=[18-135	25-135	40-135	51-135	68-60	86	91	100	104	140	145	157	174	186	196]'+140;
        yObs=[2.65261642174925	4.05982577862329	4.62406906911814	3.85379687613981	2.40000000000000	-2.10000000000000	8.30000000000000	-1.00000000000000	-0.600000000000000	2.2	2.2	-3.30000000000000	3.70000000000000	-5.80000000000000	3.70000000000000]';
        rObs=[1.15261657874791	2.55983758448023	1.87681846288179	2.44693035566188	2.95597902399321	2.07699174082087	2.00224092731988	1.14410226671952	1.53687796020374	1.99976500165112	2.35845999224188	2.60747807220875	1.76188226629708	1.13187269381181	0.87629119861599]';

        y = 0;

        yy = z(2,:,:) > 5 | z(2,:,:) < -5;
        y = y | (yy);
        for i=1:length(xObs)
                yx = (z(1,:,:) - xObs(i)).^2 + (z(2,:,:) - yObs(i)).^2 < (rObs(i)+z(3,:,:)).^2;
                y = y | yx;
        end
    end
end

function getplot(x,u,data)
    set(data.plotdisp,'XData',x(1,:),'Ydata',x(2,:),...
        'Marker','o','LineStyle','none');
    drawnow;
end

