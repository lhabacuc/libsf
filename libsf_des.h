#ifndef LIBSF_DES_H
# define LIBSF_DES_H

# include <stdbool.h>
# include "libsf.h"

#define ENDLIST(row_with_components) do { \
    GtkWidget *list_box_row = create_list_box_row(row_with_components); \
    add_widget_to_container(list_box_row, row_with_components); \
    add_row_to_list(list_box, list_box_row); \
} while (0)

#define ENDLISTR(list_box, row) do { \
    GtkWidget *list_box_row = gtk_list_box_row_new(); \
    gtk_container_add(GTK_CONTAINER(list_box_row), row); \
    gtk_container_add(GTK_CONTAINER(list_box), list_box_row); \
} while (0)

typedef struct
{
	int	x;          // Posição X do cursor
	int	y;          // Posição Y do cursor
	int	status;     // Status do evento: 1 para entrada, 0 para saída
}		Position;

typedef struct
{
	void (*callback)(GtkWidget*, gpointer, Position); // Função de callback
	gpointer	user_data; // Dados do usuário
}		HoverData;

const	char* get_theme(void);

void update_position(GtkWidget *widget, int x, int y);

Tool	*button_s(char *text);

GtkWidget* create_content_area();

void	apply_css_window(GtkWidget *widget, const gchar *css);

void	apply_global_css(const gchar *css_file_path);

void	add_css_class(GtkWidget *widget, const gchar *class_name);

void 	emove_css_class(GtkWidget *widget, const gchar *class_name);

void	set_css_property(GtkWidget *widget, const gchar *property, const gchar *value);

void	apply_css_to_named_widget(GtkWidget *widget, const gchar *css_file_path);

void	apply_css_to_widget(GtkWidget *widget, const gchar *css);

void	load_css_from_file(const gchar *filename);

void	apply_css_to_box(GtkBox *box, const gchar *css);

void	reset_widget_style(GtkWidget *widget);

GtkWidget*	create_and_add_button(GtkBox *box, const gchar *label_text);

void	apply_global_csss(GtkWidget *widget, const gchar *css_file_path);

GtkWidget*	create_styled_button(const gchar *label, const gchar *css);

GtkWidget*	create_styled_progress_bar(void);

GtkWidget*	create_button_css(const gchar *label, const gchar *bg_color, const gchar *text_color, const gchar *border_color, const gchar *focus_bg_color, char *s);

void	apply_css_to_tool(GtkWidget *widget, const gchar *css);

void	apply_css_to_window(GtkWidget *window, GtkCssProvider *css_provider);

GtkCssProvider*	create_css_provider(const gchar *css);

GtkWidget*	list_box(void);

void	add_item_to_list_box(GtkWidget *list_box, const gchar *item_label);

void	hook_list(GtkWidget *list_box, GCallback callback, gpointer user_data);

GtkWidget*	get_row(GtkListBoxRow *row);

void	apply_list_box_css(GtkWidget *list_box, gchar *css);

void	pack_widget_in_box(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding);

void	add_row_to_list(GtkWidget *list_box, GtkWidget *list_box_row);

void	add_widget_to_container(GtkWidget *container, GtkWidget *widget);

Tool	*img_padrao(int i);

GdkPixbuf*	redimensionar_imagem(const char *caminho_imagem, int largura, int altura);







#endif
