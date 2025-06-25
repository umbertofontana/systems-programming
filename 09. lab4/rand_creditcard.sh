#!/bin/bash
# Random valid credit card number generator using Luhn Algorithm (https://en.wikipedia.org/wiki/Luhn_algorithm)
# Generate 15 random digits between 0 and 9
r1=$((RANDOM % 9))
r2=$((RANDOM % 9))
r3=$((RANDOM % 9))
r4=$((RANDOM % 9))
r5=$((RANDOM % 9))
r6=$((RANDOM % 9))
r7=$((RANDOM % 9))
r8=$((RANDOM % 9))
r9=$((RANDOM % 9))
r10=$((RANDOM % 9))
r11=$((RANDOM % 9))
r12=$((RANDOM % 9))
r13=$((RANDOM % 9))
r14=$((RANDOM % 9))
r15=$((RANDOM % 9))

# Multiply every other digit by 2, starting from the first one
let d1=2*$r1
let d3=2*$r3
let d5=2*$r5
let d7=2*$r7
let d9=2*$r9
let d11=2*$r11
let d13=2*$r13
let d15=2*$r15
arr=("$d1" "$d3" "$d5" "$d7" "$d9" "$d11" "$d13" "$d15")

# If one of the multiplied by 2 digits is greater than 9, add its two digits together (or subtract 9)
i=0
for i in ${!arr[@]}
do
	if [ ${arr[$i]} -gt 9 ]
	then
		let arr[$i]=${arr[$i]}-9
	fi
done

# Sum all of the 15 digits, using the newly calculated ones
let s=${arr[0]}+$r2+${arr[1]}+$r4+${arr[2]}+$r6+${arr[3]}+$r8+${arr[4]}+$r10+${arr[5]}+$r12+${arr[6]}+$r14+${arr[7]}

# Generate the check digit
check=$(((10-($s%10))%10))

# Echo the valid credit card number
echo "$r1$r2$r3$r4$r5$r6$r7$r8$r9$r10$r11$r12$r13$r14$r15$check"
