# 仓库说明
100ASK JZ2440开发板代码仓库，仅供学习使用。

## 目录结构

- `led_run`：LED跑马灯实验代码

## 烧录说明
### 烧录环境验证
使用开发板自带烧录工具验证烧录环境，将启动模式修改为 NAND FLASH 启动，烧写命令如下：
```bash
./tools/oflash 0 1 0 0 0 ./tools/led_run.bin
```
烧录完成后重新上电，即可看到LED跑马灯效果。

### 使用OpenOCD烧录
```bash
# 终端1
make openocd

# 终端2
make upload T=led_run
s3c2440_read_block_data: reading data: 0x62e80dfa1820, 0x7ffe4bd11212, 6
s3c2440_read_block_data: reading data: 0x62e80dfa1820, 0x7ffe4bd11212, 6
Write led_run to Nand Flash Done!
```
烧录完成后重新上电，即可看到LED跑马灯效果。

### 使用GDB调试
```bash
make openocd

# 终端2
make run_gdb T=led_run
```
烧录完成后重新上电，即可看到LED跑马灯效果。


