

default:
	gcc -o main -g -fno-stack-protector -m32 -z execstack main.c

attack: default
	./exe_attack.sh 

clean:
	rm main
