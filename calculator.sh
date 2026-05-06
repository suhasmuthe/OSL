#!/bin/bash 
# Simple Calculator using Bash Script 
 
echo "===== Simple Calculator =====" 
echo "" 
 
# Input first number 
echo "Enter first number:" 
read num1 
 
# Input operator 
echo "Enter operator (+, -, *, /):" 
read op 
 
# Input second number 
echo "Enter second number:" 
read num2 
 
# Perform calculation based on operator 
case $op in 
    +) 
        result=$(echo "$num1 + $num2" | bc) 
        echo "" 
        echo "Result: $num1 + $num2 = $result" 
        ;; 
    -) 
        result=$(echo "$num1 - $num2" | bc) 
        echo "" 
        echo "Result: $num1 - $num2 = $result" 
        ;; 
    \*) 
        result=$(echo "$num1 * $num2" | bc) 
        echo "" 
        echo "Result: $num1 * $num2 = $result" 
        ;; 
    /) 
        if [ $num2 -eq 0 ]; then 
            echo "" 
            echo "Error: Division by zero!" 
        else 
            result=$(echo "scale=2; $num1 / $num2" | bc) 
            echo "" 
            echo "Result: $num1 / $num2 = $result" 
        fi 
        ;; 
    *) 
        echo "" 
        echo "Error: Invalid operator! Please use +, -, *, or /" 
        ;; 
esac 
 
echo "" 
echo "============================="