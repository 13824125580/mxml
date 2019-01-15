all:
	gcc -L../mxml/ xml.c -lmxml -o test1
	gcc -L../mxml/ xml2.c -lmxml -o test2
	gcc -L../mxml/ xml3.c -lmxml -o test3
	gcc -L../mxml/ qq.c -lmxml -o qq
	gcc -L../mxml/ tianqi.c -lmxml -o tianqi
