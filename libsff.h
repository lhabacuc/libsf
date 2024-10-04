#ifndef LIBSFF_H
# define LIBSFF_H

# include <gtk/gtk.h>

# define MAX_LINE_LENGTH 256
# define MAX_KEY_LENGTH 128
# define MAX_VALUE_LENGTH 128
# define TEMP_FILE "temp.db"
# define PUBLIC_DIR ".data_app"

# define OBJ GtkWidget
# define Tool GtkWidget
# define F(o) G_CALLBACK(o)
# define Sbox GtkListBox
# define Pont gpointer
# define BoxRow GtkListBoxRow
# define String char*
# define Vtor int*
# define Appl GtkApplication
# define	sf_init(argc, argv) gtk_init(&(argc), &(argv))

// Macros para eventos de mouse
# define BUTTON_PRESS_EVENT "button-press-event"
# define BUTTON_RELEASE_EVENT "button-release-event"
# define MOTION_NOTIFY_EVENT "motion-notify-event"

// Macros para eventos de teclado
# define KEY_PRESS_EVENT "key-press-event"
# define KEY_RELEASE_EVENT "key-release-event"
# define CLICK "clicked"

// Macros para outros eventos
# define ENTER_NOTIFY_EVENT "enter-notify-event"
# define LEAVE_NOTIFY_EVENT "leave-notify-event"
# define SCROLL_EVENT "scroll-event"
# define WINDOW_STATE_EVENT "window-state-event"

// Definições dos códigos para as setas direcionais compatíveis com
# define UP_ARROW       GDK_KEY_Up       // Up Arrow
# define DOWN_ARROW     GDK_KEY_Down     // Down Arrow
# define LEFT_ARROW     GDK_KEY_Left     // Left Arrow
# define RIGHT_ARROW    GDK_KEY_Right    // Right Arrow

# define SETA_CIMA      GDK_KEY_Up
# define SETA_BAIXO     GDK_KEY_Down
# define SETA_ESQUERDA  GDK_KEY_Left
 #define SETA_DIREITA   GDK_KEY_Right

// Códigos de eventos de teclado
# define TECLA_ENTER      GDK_KEY_Return     // Enter Key
# define TECLA_ESC        GDK_KEY_Escape     // Escape Key
# define TECLA_TAB        GDK_KEY_Tab        // Tab Key
# define TECLA_BACKSPACE  GDK_KEY_BackSpace  // Backspace Key
# define TECLA_DELETE     GDK_KEY_Delete     // Delete Key
# define TECLA_HOME       GDK_KEY_Home       // Home Key
# define TECLA_END        GDK_KEY_End        // End Key
# define TECLA_PAGEUP     GDK_KEY_Prior      // Page Up Key
# define TECLA_PAGEDOWN   GDK_KEY_Next       // Page Down Key

// Códigos de eventos de mouse
# define MOUSE_LEFT_CLICK   GDK_BUTTON_PRIMARY   // Left Mouse Button
# define MOUSE_RIGHT_CLICK  GDK_BUTTON_SECONDARY // Right Mouse Button
# define MOUSE_MIDDLE_CLICK GDK_BUTTON_MIDDLE    // Middle Mouse Button
# define MOUSE_SCROLL_UP    GDK_SCROLL_UP        // Scroll Up
# define MOUSE_SCROLL_DOWN  GDK_SCROLL_DOWN      // Scroll Down

// Estados da janela
# define JANELA_MINIMIZADA  GDK_WINDOW_STATE_ICONIFIED  // Minimized Window
# define JANELA_MAXIMIZADA  GDK_WINDOW_STATE_MAXIMIZED  // Maximized Window
# define JANELA_NORMAL      GDK_WINDOW_STATE_NORMAL     // Normal Window

// Modificadores de teclado
# define MOD_CTRL   GDK_CONTROL_MASK  // Ctrl Key
# define MOD_SHIFT  GDK_SHIFT_MASK    // Shift Key
# define MOD_ALT    GDK_MOD1_MASK     // Alt Key

// Funções comuns
# define FUNCAO_ABRIR  gtk_file_chooser_dialog_new   // Open File Dialog
# define FUNCAO_SALVAR gtk_file_chooser_dialog_new   // Save File Dialog
# define FUNCAO_MENSAGEM gtk_message_dialog_new      // Message Dialog
# define FUNCAO_NOTIFICACAO gtk_notification_new      // Notification

# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define YELLOW  0xFFFF00
# define CYAN    0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY    0x808080
# define ORANGE  0xFFA500
# define PURPLE  0x800080
# define BROWN   0xA52A2A
# define PINK    0xFFC0CB

# define SKY_BLUE     0x87CEEB
# define FOREST_GREEN 0x228B22
# define SLATE_GRAY   0x708090
# define INDIGO       0x4B0082
# define CORAL        0xFF7F50
# define LIGHT_CYAN   0xE0FFFF
# define DEEP_PINK    0xFF1493
# define ORCHID       0xDA70D6
# define TOMATO       0xFF6347
# define GOLD         0xFFD700
# define TEAL         0x008080
# define MIDNIGHT_BLUE 0x191970
# define SADDLEBROWN  0x8B4513
# define TAN          0xD2B48C
# define SALMON       0xFA8072

# define MAP_SIZE 100
# define FILE_NAME "map_data.txt"

#define BIN_LISTVIEW(bin, text)           \
    do {                                             \
        GtkWidget *widget = gtk_bin_get_child(GTK_BIN(bin)); \
        text = NULL;                                \
        GList *children = gtk_container_get_children(GTK_CONTAINER(widget)); \
        for (GList *iter = children; iter != NULL; iter = iter->next) { \
            GtkWidget *child = GTK_WIDGET(iter->data); \
            if (GTK_IS_LABEL(child)) {                \
                text = gtk_label_get_text(GTK_LABEL(child)); \
                break;                              \
            }                                       \
        }                                           \
        g_list_free(children);                       \
    } while (0)


#define	sf_printf(fmt, ...) g_print(fmt, ##__VA_ARGS__)

#define sf_show(window) \
    do { \
        gtk_widget_show_all(window); \
        gtk_main(); \
    } while (0)

#define set_margem_cima(widget, valor) gtk_widget_set_margin_top(widget, valor)
#define set_margem_baixo(widget, valor) gtk_widget_set_margin_bottom(widget, valor)
#define set_margem_esquerda(widget, valor) gtk_widget_set_margin_start(widget, valor)
#define set_margem_direita(widget, valor) gtk_widget_set_margin_end(widget, valor)



typedef void (*BCall)(GtkWidget *button, Pont data);
typedef void (*ECall)(GtkWidget *Etext, Pont data);
typedef void (*SignalCallback)(GtkWidget *, Pont);

typedef struct s_keyvalue
{
	char				*key;
	char				*value;
	struct s_keyvalue	*next;
}	t_keyvalue;

typedef struct s_map
{
	t_keyvalue	*buckets[MAP_SIZE];
}	t_map;

/*	Funções renomeadas	*/

#endif 
