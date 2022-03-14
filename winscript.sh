#!/bin/bash
#Place here the two bots wou want to battle.
BOT2=./born2bebot
BOT1=../duco/bot
N_GAMES=500

echo "" > winstats.txt
for ((i = 0; i < $N_GAMES; i++))
do
	../duco/cluster $BOT1 $BOT2 >> winstats.txt 2>&1
done
echo "We play $N_GAMES games!"
P1WON=$(cat winstats.txt | grep wins | grep 1 | wc -l | awk '{print $1}')
P2OUT=$(cat winstats.txt | grep chips | grep 2 | wc -l | awk '{print $1}')
echo "wins player 1 = $P1WON.		p2 Out of chips = $P2OUT"

P2WON=$(cat winstats.txt | grep wins | grep 2 | wc -l | awk '{print $1}')
P1OUT=$(cat winstats.txt | grep chips | grep 1 | wc -l | awk '{print $1}')
echo "wins player 2 = $P2WON.		p1 Out of chips = $P1OUT"


