#!/bin/zsh

./lemipc --army=1 & ./lemipc --army=2 & ./lemipc --army=3 &

./disp &

sleep 2

for ((i = 0; i < 10; i += 1))
do
    ./lemipc --army=1 &
done

for ((i = 0; i < 10; i += 1))
do
    ./lemipc --army=2 &
done

for ((i = 0; i < 10; i += 1))
do
    ./lemipc --army=3 &
done

for ((i = 0; i < 10; i += 1))
do
    ./lemipc --army=4 &
done

for ((i = 0; i < 10; i += 1))
do
    ./lemipc --army=5 &
done
