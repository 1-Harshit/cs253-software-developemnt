#!/usr/bin/bash

# read a filename
ifile=$1
ofile=$2

# If all arguements given
if [ $# != 2 ]; then
	echo "Usage: $0 <in_file> <out_file>"
	exit
fi

# check if file1 exists
if ! [ -f "$ifile" ]; then
	echo "[ERR] $ifile does not exist"
	exit
fi

# Filter data from csv
awk -F "\"*,\"*" '{print $1" "$2" "$3" "$5" "$6" "$7" "$10" "$11}' "$ifile" >"$ofile"

# Get Bachelor's College Name
echo "" >> "$ofile"
echo "Name of Bachelor's College" >> "$ofile"
awk -F "\"*,\"*" '{
	if ($3 == "Bachelor'\''s")
	print $1
	}' "$ifile" >>"$ofile"

# Average Admission rate by geography
echo "" >> "$ofile"
echo "Geography: Average Admission Rate" >>"$ofile"
awk -F "\"*,\"*" '
		{arr[$6]++}\
		{rat[$6]+=$7}
		END{for (a in arr) print a, rat[a]/arr[a]}
	' "$ifile" >>"$ofile"

# top five colleges who have maximum MedianEarnings
echo "" >> "$ofile"
echo "Top five colleges who have maximum MedianEarnings" >>"$ofile"
echo "Name MedianEarnings" >>"$ofile"
sort -t , -k 16 -r -n "$ifile" | awk -F "\"*,\"*" 'NR<=5 {print $1,$16}' >> "$ofile"
