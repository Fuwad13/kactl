# A and B are executables you want to compare, gen takes int
# as command line arg. Usage: 'sh stress.sh'
for ((i = 1; ; ++i)); do  # if they are same then will loop forever
    echo $i
    ./gen $i > inp
    ./A < inp > out1
    ./B < inp > out2
    diff -w out1 out2 || break
    # diff -w <(./A < inp) <(./B < inp) || break
done


# We can modify this to work for other situations. For example, if you have input and output files (e.g., 1.in, 1.out, 2.in, 2.out, ..., 10.out for old USACO problems) then you can use the following:

# A is the executable you want to test
#for ((i = 1; i <= 10; ++i)); do
#    echo $i
#    ./A < $i.in > out
#    diff -w out $i.out || break
#done
#echo "ALL TESTS PASSED"


# The following will break on the first input file such that the produced output file is empty.

#for((i = 1; ; ++i)); do
#	echo $i
#	./gen $i > inp
#	./A < inp > out
#	if ! [[ -s "out" ]] ; then
#		echo "no output"
#		break
#	fi ;
#done
