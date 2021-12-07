#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette
echo -e "\033[32;1m"ft_printf_tester TEST"\033[m"
read $a
git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester/
bash test
cd ..
echo -e "\033[32;1m"printfTester"\033[m"
read $a
git clone https://github.com/Tripouille/printfTester.git
cd printfTester/
make a
cd ..
echo -e "\033[32;1m"make fclean"\033[m"
read $a
make
make fclean
ls
echo -e "\033[32;1m"make clean"\033[m"
read $a
make
make clean
ls
echo -e "\033[32;1m"make all"\033[m"
read $a
make all
ls
echo -e "\033[32;1m"make bonus"\033[m"
read $a
make bonus
ls
echo -e "\033[32;1m"make re"\033[m"
read $a
make re
echo -e "\033[32;1m"remove"\033[m"
read $a
rm -rf printfTester/ ft_printf_tester/
make fclean
echo -e "\033[32;1m"DONE"\033[m"
