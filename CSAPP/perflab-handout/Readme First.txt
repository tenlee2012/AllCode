--本次实验为程序性能调优实验。

--实验发布“perflab-handout”包，需要进行操作的主要为kernel.c和driver.c文件，其中kernel.c文件为修改优化代码的源文件，driver.c文件用于编译生成对kernel.c代码修改的效果进行评价、并给出详细性能结果的driver执行文件。

--解压后，通过查看目录下的makefile文件可看到不同的make过程都做了什么。一般来讲，我们可以make clean后，再make all，从而生成driver执行文件。

--其后，用./driver 直接执行，则会在终端打印出对此目录下的kernel.c文件中的Registered的函数的性能评价。因此，本次实验的核心任务是要求大家修改kernel.c文件，并可以在使用driver进行评测时获得更好的加速比。

--kernel.c文件请大家仔细看注释说明，如何注册（register）你所写的函数，从而可以让driver找到、并评价之。

--kernel.c文件中主要有两个需要进行优化的函数：rotate和smooth，并分别给出了naive_rotate和naive_smooth两个函数的基本实现作为baseline作为你改进后的程序的比较对象。你需要读懂rotate和smooth函数，并对其进行优化。你每写一个新版本的、优化的rotate和smooth函数，均可在成注册后使用driver进行测试，并得到对应的CPE和加速比。

--实验要求：本次实验，要求针对每个函数、每个人均至少写出3种优化版本、并根据driver报告的结果进行性能分析。