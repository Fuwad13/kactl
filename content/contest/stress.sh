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
