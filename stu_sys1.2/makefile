bin/stu:	obj/control.o	obj/file_wr_rd.o	 obj/fun_login.o	obj/fun_stu.o	obj/link.o	obj/top_view.o
	gcc obj/*.o src/main.c -o bin/stu -I include/ -Wall -g


obj/control.o: src/control.c include/control.h
	gcc -c src/control.c -o obj/control.o -I include/ -Wall -g

obj/file_wr_rd.o: src/file_wr_rd.c include/file_wr_rd.h
	gcc -c src/file_wr_rd.c -o obj/file_wr_rd.o -I include/ -Wall -g

obj/fun_login.o: src/fun_login.c include/fun_login.h
	gcc -c src/fun_login.c -o obj/fun_login.o -I include/ -Wall -g

obj/fun_stu.o: src/fun_stu.c include/fun_stu.h
	gcc -c src/fun_stu.c -o obj/fun_stu.o -I include/ -Wall -g

obj/link.o: src/link.c include/link.h
	gcc -c src/link.c -o obj/link.o -I include/ -Wall -g

obj/top_view.o: src/top_view.c include/top_view.h
	gcc -c src/top_view.c -o obj/top_view.o -I include/ -Wall -g

clean:
	rm -rf obj/* bin/* 
