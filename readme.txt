├─peripheral：外设库 
├─hardware：硬件驱动
├─library：外设库源文件
├─MDK：keil生成，是一些目标文件和中间文件
│  ├─DebugConfig
│  ├─Listings
│  └─Objects
├─OS：所移植的系统源文件
│  ├─task.c：用户编写的任务
│  ├─task.h
│  ├─config
│  ├─inc
│  └─src
├─Startup：
│      core_cm4.h：内核寄存器的定义
│      core_cmFunc.h----+
│      core_cmInstr.h	  |----操作内核相关文件
│      core_cmSimd.h---+
│      startup_stm32f40_41xxx.s：启动文件
│      stm32f4xx.h：外设寄存器的定义
│      system_stm32f4xx.c：系统初始化，配置系统时钟
│      system_stm32f4xx.h
│
d└─User
        main.c
        main.h
        stm32f4xx_conf.h：具体板卡型号的配置
        stm32f4xx_it.c：用户编写的中断服务程序
        stm32f4xx_it.h

