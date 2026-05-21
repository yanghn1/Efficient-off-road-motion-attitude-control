# Efficient-off-road-motion-attitude-control
The combination of motion control and attitude control opens up the possibility of alleviating the long-standing research challenges for autonomous vehicle tracking task in off-road environments. Inspire by this, an efficient motion-attitude integration control strategy is proposed.

代码分为仿真和FPGA两部分，仿真部分在MPPIcode和m_simulation，FPGA部分在c_FPGA中

环境准备

仿真部分需要的环境为Carsim2020以上版本，以及Matlab2023a以上的版本，FPGA则需要准备heterogeneous chip Zynq核心板

MPPIcode部分在装好的Matlab中直接运动main文件即可看到基于MPPI生成的全局规划轨迹
m_simulation部分运行，首先将cpar文件导入到Carsim2020，然后运行对应的main文件即可生成不同算法的控制效果图
FPGA中提供了对应的c语言文件，将该文件下载到heterogeneous chip Zynq核心板中进行联防可得到对应的控制效果图
