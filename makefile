compile: main.c 
	 gcc main.c -o keem

run: keem
	 ./keem
   
clean: keem
	 rm keem