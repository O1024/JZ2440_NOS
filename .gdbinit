target extended-remote localhost:3333

printf "------------------------------------------\n"
printf ">>> echo \"monitor h\" to get help message. \n"
printf "------------------------------------------\n"

define gdb_flash_bin
   monitor flash_bin $arg0 
   echo "Write $arg0 to Nand Flash Done!\n"
end

define gdb_debug_flash_bin
    file $arg0
    load
    b main
    c
end

