# libsf
CC = cc

CFLAGS = -I/usr/include/gtk-3.0 -I/usr/include/glib-2.0 \
		-I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ \
		-I/usr/include/pango-1.0 -I/usr/include/harfbuzz \
		-I/usr/include/cairo -I/usr/include/gdkpixbuf-2.0 \
		-I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gio-unix-2.0/ \
		-I/usr/include/gtk-3.0/gdk/ -I/usr/include/gtk-3.0/gtk/ \
		-I/usr/include/glib-2.0/glib/ -I/usr/include/pango-1.0/pango/ \
		-I/usr/include/atk-1.0/ -I/usr/include/atk/ \
		`pkg-config --cflags --libs gtk+-3.0` \
		`pkg-config --cflags --libs glib-2.0` \
		`pkg-config --cflags --libs gdk-pixbuf-2.0` \
		`pkg-config --cflags --libs pango` \
		`pkg-config --cflags --libs cairo` \
		`pkg-config --cflags --libs gio-unix-2.0`

LIB_NAME = libsf.a

OBSJ = lib_sf.c \
	libsf_db.c \
	libmap.c \
	libsf_init.c \
	libsf_creat.c \
	libsf_bin.c \
	libsf_box.c \
	libsf_grid.c \
	libsf_des.c 

SRC = $(OBSJ)
OBJ = $(SRC:.c=.o)

INCLUDES = -I.

GTKFLAGS = -I/usr/include/gtk-3.0 -I/usr/include/glib-2.0 \
		-I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ \
		-I/usr/include/pango-1.0 -I/usr/include/harfbuzz \
		-I/usr/include/cairo -I/usr/include/gdkpixbuf-2.0 \
		-I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gio-unix-2.0/ \
		-I/usr/include/gtk-3.0/gdk/ -I/usr/include/gtk-3.0/gtk/ \
		-I/usr/include/glib-2.0/glib/ -I/usr/include/pango-1.0/pango/ \
		-I/usr/include/atk-1.0/ -I/usr/include/atk/ \
		`pkg-config --cflags --libs gtk+-3.0` \
		`pkg-config --cflags --libs glib-2.0` \
		`pkg-config --cflags --libs gdk-pixbuf-2.0` \
		`pkg-config --cflags --libs pango` \
		`pkg-config --cflags --libs cairo` \
		`pkg-config --cflags --libs gio-unix-2.0`

all: $(LIB_NAME)
	clear

$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(LIB_NAME)
re: fclean all

.PHONY: all clean fclean re test
# test gcc -o programa test.c -I./libsf-s -L./libsf-s -lsf `pkg-config --cflags --libs gtk+-3.0`
