bin/a.out: obj/hide.o obj/gref.o obj/buy_link.o obj/ticket_link.o obj/admin.o obj/user.o obj/user_link.o obj/login_view.o obj/control.o
	gcc obj/*.o src/main.c -o bin/a.out -I inc/ -Wall -g

obj/hide.o: src/hide.c inc/hide.h
	gcc -c src/hide.c -o obj/hide.o -I inc/ -Wall -g

obj/gref.o: src/gref.c inc/gref.h
	gcc -c src/gref.c -o obj/gref.o -I inc/ -Wall -g

obj/buy_link.o: src/buy_link.c inc/buy_link.h
	gcc -c src/buy_link.c -o obj/buy_link.o -I inc/ -Wall -g

obj/ticket_link.o: src/ticket_link.c inc/ticket_link.h
	gcc -c src/ticket_link.c -o obj/ticket_link.o -I inc/ -Wall -g

obj/admin.o: src/admin.c inc/admin.h
	gcc -c src/admin.c -o obj/admin.o -I inc/ -Wall -g

obj/user.o: src/user.c inc/user.h
	gcc -c src/user.c -o obj/user.o -I inc/ -Wall -g

obj/control.o: src/control.c inc/control.h
	gcc -c src/control.c -o obj/control.o -I inc/ -Wall -g

obj/login_view.o: src/login_view.c inc/login_view.h
	gcc -c src/login_view.c -o obj/login_view.o -I inc/ -Wall -g

obj/user_link.o: src/user_link.c inc/user_link.h
	gcc -c src/user_link.c -o obj/user_link.o -I inc/ -Wall -g

clean:
	rm -rf obj/* bin/* data/*
