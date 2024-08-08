#ifndef LIBSF_H
# define LIBSF_H

# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <gtk/gtk.h>
# include <errno.h>

# define MAX_LINE_LENGTH 256
# define MAX_KEY_LENGTH 128
# define MAX_VALUE_LENGTH 128
# define TEMP_FILE "temp.db"
# define PUBLIC_DIR ".data_app"

# define OBJ GtkWidget
# define Tool GtkWidget
# define F(o) G_CALLBACK(o)
# define String char*
# define Vtor int*

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
#define UP_ARROW       GDK_KEY_Up       // Up Arrow
#define DOWN_ARROW     GDK_KEY_Down     // Down Arrow
#define LEFT_ARROW     GDK_KEY_Left     // Left Arrow
#define RIGHT_ARROW    GDK_KEY_Right    // Right Arrow

#define SETA_CIMA      GDK_KEY_Up
#define SETA_BAIXO     GDK_KEY_Down
#define SETA_ESQUERDA  GDK_KEY_Left
#define SETA_DIREITA   GDK_KEY_Right

// Códigos de eventos de teclado
#define TECLA_ENTER      GDK_KEY_Return     // Enter Key
#define TECLA_ESC        GDK_KEY_Escape     // Escape Key
#define TECLA_TAB        GDK_KEY_Tab        // Tab Key
#define TECLA_BACKSPACE  GDK_KEY_BackSpace  // Backspace Key
#define TECLA_DELETE     GDK_KEY_Delete     // Delete Key
#define TECLA_HOME       GDK_KEY_Home       // Home Key
#define TECLA_END        GDK_KEY_End        // End Key
#define TECLA_PAGEUP     GDK_KEY_Prior      // Page Up Key
#define TECLA_PAGEDOWN   GDK_KEY_Next       // Page Down Key

// Códigos de eventos de mouse
#define MOUSE_LEFT_CLICK   GDK_BUTTON_PRIMARY   // Left Mouse Button
#define MOUSE_RIGHT_CLICK  GDK_BUTTON_SECONDARY // Right Mouse Button
#define MOUSE_MIDDLE_CLICK GDK_BUTTON_MIDDLE    // Middle Mouse Button
#define MOUSE_SCROLL_UP    GDK_SCROLL_UP        // Scroll Up
#define MOUSE_SCROLL_DOWN  GDK_SCROLL_DOWN      // Scroll Down

// Estados da janela
#define JANELA_MINIMIZADA  GDK_WINDOW_STATE_ICONIFIED  // Minimized Window
#define JANELA_MAXIMIZADA  GDK_WINDOW_STATE_MAXIMIZED  // Maximized Window
#define JANELA_NORMAL      GDK_WINDOW_STATE_NORMAL     // Normal Window

// Modificadores de teclado
#define MOD_CTRL   GDK_CONTROL_MASK  // Ctrl Key
#define MOD_SHIFT  GDK_SHIFT_MASK    // Shift Key
#define MOD_ALT    GDK_MOD1_MASK     // Alt Key

// Funções comuns
#define FUNCAO_ABRIR  gtk_file_chooser_dialog_new   // Open File Dialog
#define FUNCAO_SALVAR gtk_file_chooser_dialog_new   // Save File Dialog
#define FUNCAO_MENSAGEM gtk_message_dialog_new      // Message Dialog
#define FUNCAO_NOTIFICACAO gtk_notification_new      // Notification

//gcc -o app t.c -I./libsf-s -L./libsf-s -lsf `pkg-config --cflags --libs gtk+-3.0`

// Estrutura para gerenciar diferentes janelas no aplicativo
typedef struct s_window_manager
{
	GtkWidget	*main_window;		// Janela principal
	GtkWidget	*settings_window;	// Janela de configurações
	GtkWidget	*content_window;	// Janela de conteúdo
	GtkWidget	*dialog_window;		// Janela de diálogo
	GtkWidget	*tools_window;		// Janela de ferramentas
	GtkWidget	*help_window;		// Janela de ajuda
	GtkWidget	*temp_window;		// Janela temporária
	GtkWidget	*fixed_layout_window;	// Janela com layout fixo
	GtkWidget	*grid_layout_window;	// Janela com layout em grid
	GtkWidget	*data_window;		// Janela com dados
	GtkWidget	*preview_window;	// Janela de visualização
	GtkWidget	*widget; 		// O próprio widget GTK
	GtkWidget	*area_desenho;		// Área de desenho (se houver)
	GtkWidget	*barra_status;		// Barra de status
	GtkWidget	*menu_principal;	// Menu principal
	GtkWidget	*painel_ferrament;
	gint		x;			// Coordenada X
	gint		y;			// Coordenada Y
	gint		largura;		// Largura do widget
	gint		altura; 
}			t_window_manager;

typedef struct
{
	GtkWidget	*widget;	// O próprio widget (por exemplo, um botão, etiqueta,...)
	int	x;			// Coordenada X do obj na janela
	int	y;			// Coordenada Y do obj na janela
	int	largura;		// Largura do objeto
	int	altura;		// Altura do objeto
	gboolean	visivel;	// Flag para verificar se o objeto está visível
	void	(*desenho_callback)(GtkWidget *, cairo_t *, gpointer);	// F para desenhar o obj
	gpointer	dados;	// Dados add++ para o objeto (por ex:, configurações ou estados)
}			Objeto;

typedef struct
{
	void	(*key_handler)(GdkEventKey *event, gpointer user_data);
	gpointer	user_data;
}			t_key_event_data;

typedef struct
{
	void	(*mouse_handler)(GdkEventButton *event, gpointer user_data);
	gpointer	user_data;
}			t_mouse_event_data;

typedef struct
{
	void	(*loop_handler)(gpointer user_data);
	gpointer	user_data;
}			t_loop_event_data;

/*	database sharepreferense	*/
void		add_or_update_record(const char *db_name, const char *key, const char *value, const char *arquivo);
void		create_directory(const char *path);
void		create_new_database(const char *db_name, const char *arquivo);
char		*get_value(const char *db_name, const char *key, const char *arquivo);
void		listar_registros(const char *db_name, const char *arquivo);
void		delete_record(const char *db_name, const char *key, const char *arquivo);


GtkWidget	*add_fixed_layout_to_window(GtkWidget *window);
GtkWidget	*create_context_menu(GtkWidget *widget, GCallback callback, gpointer data);
GtkWidget	*create_window_s(const char *title, int width, int height);
GtkWidget	*add_button(GtkWidget *container, const char *label, int x, int y, GCallback callback);
GtkWidget	*add_label(GtkWidget *container, const char *text, int x, int y);
GtkWidget	*add_entry(GtkWidget *container, int x, int y, GCallback callback);
GtkWidget	*add_color_chooser(GtkWidget *container, int x, int y, GCallback callback);
GtkWidget	*add_drawing_area(GtkWidget *container, int x, int y,
				int width, int height, GCallback draw_callback);
GtkWidget	*add_file_chooser(GtkWidget *container, int x, int y, GCallback callback);
GtkWidget	*add_image(GtkWidget *container, const char *file_path, int x, int y);
GtkWidget	*add_separator(GtkWidget *container, int x, int y, gboolean horizontal);
GtkWidget	*add_volume_slider(GtkWidget *container, int x, int y, GCallback callback);
GtkWidget	*add_checkbox(GtkWidget *container, const char *label, int x, int y, GCallback callback);
GtkWidget	*add_radio_button(GtkWidget *container,
				GtkWidget *group, const char *label, int x, int y);
GtkWidget	*add_combo_box(GtkWidget *container, int x, int y,
				gchar **items, int item_count, GCallback callback);
GtkWidget	*add_calendar(GtkWidget *container, int x, int y, GCallback callback);
GtkWidget	*add_status_bar(GtkWidget *container, int x, int y);
GtkWidget	*add_context_menu(GtkWidget *widget, GtkWidget *menu);
GtkWidget	*add_toolbar_with_buttons(GtkWidget *container, const char **button_labels, int count);
GtkWidget	*add_spinner(GtkWidget *container, int x, int y);
GtkWidget	*add_text_view(GtkWidget *container, int x, int y, int width, int height);

GtkWidget	*create_image_with_position(GtkWidget *container, const char *file_path,
					int x, int y, int width, int height);
GtkWidget	*create_scale_with_position(GtkWidget *container,
					int x, int y, int min, int max, int step);
GtkWidget	*create_checkbox_with_position(GtkWidget *container,
				const char *label, int x, int y, gboolean active);
GtkWidget	*create_drawing_area_with_position(GtkWidget *container,
			int x, int y, int width,int height,
			gboolean (*draw_callback)(GtkWidget *, cairo_t *, gpointer), gpointer data);
GtkWidget	*create_label_with_position(GtkWidget *container, const char *text,
				int x, int y, const GdkRGBA *color);
GtkWidget	*create_button_with_position(GtkWidget *container, const char *label,
				int x, int y, void (*callback)(GtkWidget *, gpointer), gpointer data);

GtkWidget	*create_check_button(const char *label, gboolean initial_state);
GtkWidget	*create_progress_bar(double initial_fraction);
GtkWidget	*create_spin_button(double min, double max, double step, double initial_value);
GtkWidget	*create_combo_box(const char **items, int num_items, int default_index);
GtkWidget	*create_image_ph(GtkWidget *container, const char
					*file_path, gint x, gint y, gint width, gint height);
GtkWidget	*create_vbox(gboolean homogeneous, gint spacing);
GtkWidget	*create_hbox(gboolean homogeneous, gint spacing);
GtkWidget	*create_grid(gint row_spacing, gint column_spacing);
GtkWidget	*create_fixed_layout(void);
GtkWidget	*create_entry1(GtkFixed *fixed, gint x, gint y, const char *border_color,
					void (*callback)(GtkEntry *, gpointer));
GtkWidget	*create_label(GtkWidget *container, const char *text);
GtkWidget	*create_text_view(GtkWidget *container);
GtkWidget	*new_window(const char *title, int width, int height);


void		loop(gpointer user_data, void (*init_callback)(gpointer));
void		hook(GtkWidget *widget, const gchar *event_name, GCallback callback, gpointer user_data);
void		set_background_color(GtkWidget *widget, const gchar *color);
void		hide_widget(GtkWidget *widget);
void		show_widget(GtkWidget *widget);
void		pixel_put(GtkWidget *drawing_area, int x, int y, double red, double green, double blue);
void		hook_key(GtkWidget *widget, void (*key_handler)(GdkEventKey *event, gpointer user_data), gpointer user_data);
void		set_size(GtkWidget *widget, int width, int height);
void		loop_window(GtkWidget *window);
void		init_windows(t_window_manager *wm);
void		add_event(GtkWidget *widget, const char *event_name, GCallback callback);
void		add_to_fixed(GtkFixed *fixed, GtkWidget *widget, gint x, gint y);
void		add_to_grid(GtkGrid *grid, GtkWidget *widget, guint left,
			guint top, guint width, guint height);
void		apply_css(GtkWidget *widget, const char *css);
void		set_button_color(GtkWidget *button, const char *color);
void		set_label_color(GtkWidget *label, const char *color);
void		set_entry_border_color(GtkWidget *entry, const char *color);
void		create_image(GtkFixed *fixed, const char *file_path, gint x, gint y);
void		create_entry(GtkFixed *fixed, gint x, gint y);
void		add_tabs(GtkWidget *notebook, GtkWidget **pages, const char **titles, int count);
void		create_text(GtkFixed *fixed, const char *text, gint x, gint y);
void		create_button(GtkFixed *fixed, const char *label, gint x,
			gint y, void (*callback)(GtkWidget *, gpointer), gpointer user_data);
void		show_notification(GtkWidget *parent, const char *title, const char *message);
void		set_mouse_event_handler(GtkWidget *widget,
			void (*handler)(GdkEventButton *, gpointer), gpointer user_data);
void		add_tab_to_notebook(GtkWidget *notebook, const char *label, GtkWidget *content);
void		set_key_event_handler(GtkWidget *widget,
				void (*handler)(GdkEventKey *, gpointer), gpointer user_data);
void		set_loop_event_handler(guint interval, void (*handler)(gpointer), gpointer user_data);
void		reposition_widget_in_grid(GtkGrid *grid, GtkWidget *widget, int left, int top);
void		set_status_bar_message(GtkWidget *status_bar, const char *message);
void		color_activated(GtkColorChooser *chooser, gpointer user_data);
GtkWidget	*create_image_c(GtkWidget *container, const char *file_path);
GtkWidget	*create_calendar(GtkWidget *container);
GtkWidget	*create_file_chooser_button(GtkWidget *container, const char *title,
                                      GtkFileChooserAction action, GCallback callback, gpointer data);
GtkWidget	*create_color_chooser(GtkWidget *container, GCallback callback, gpointer data);
GtkWidget	*create_notebook(GtkWidget *container);
GtkWidget	*create_media_viewer(GtkWidget *container);
GtkWidget	*create_toolbar(GtkWidget *container);
GtkToolItem	*create_toolbar_button(GtkWidget *toolbar, const char *icon_name,
				const char *tooltip, GCallback callback, gpointer data);
GtkWidget	*add_widget_at_position(GtkWidget *fixed_container, GtkWidget *widget, int x, int y);
GtkWidget	*create_color_chooser_with_position(GtkWidget *container, int x, int y,
				int width, int height, GdkRGBA *color);

#endif // LIBSF_H

