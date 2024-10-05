#ifndef libsf_grid_h
# define libsf_grid_h

# include <stdbool.h>
# include "libsf.h"
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// funcao para criar combo box
#define criate_combox() \
	gtk_combo_box_text_new()

// funcao para adicionar um item ao final do combo box de texto
#define add_data_text(combo, id, text) \
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), id, text)

// funcao para adicionar um item no início do combo box de texto
#define prepend_data_text(combo, id, text) \
	gtk_combo_box_text_prepend(GTK_COMBO_BOX_TEXT(combo), id, text)

// funcao para remover um item do combo box de texto pelo índice
#define remove_data_text(combo, index) \
	gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(combo), index)

// funcao para definir o item ativo no combo box de texto usando um ID
#define set_active_text(combo, id) \
	gtk_combo_box_set_active_id(GTK_COMBO_BOX(combo), id)

// funcao para obter o texto do item ativo no combo box de texto
#define get_active_text(combo) \
	gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo))

// funcao para limpar todos os itens do combo box de texto
#define clear_combo(combo) \
	gtk_combo_box_text_clear(GTK_COMBO_BOX_TEXT(combo))

// funcao para definir um texto de dica (tooltip) para o combo box
#define set_tooltip(combo, tooltip) \
	gtk_widget_set_tooltip_text(GTK_WIDGET(combo), tooltip)

// funcao para inserir um item em uma posição específica no combo box de texto
#define insert_data_text(combo, index, text) \
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(combo), index, NULL, text)

// funcao para definir a coluna de texto de entrada no combo box
#define set_entry_column(combo, column) \
	gtk_combo_box_set_entry_text_column(GTK_COMBO_BOX(combo), column)


typedef struct s_element
{
	char name[50];
	struct s_element *children;
	struct s_element *next;
	char parent[50];
}	t_element;

# define button_void() gtk_button_new()

void	apply_css_file(GtkWidget *widget, const gchar *css_file_path);
GtkWidget	*botton_icone(const char *icone_caminho, const char *texto,
				int largura, int altura, int margem, const char *tooltip);
GtkWidget* create_grid(gint row_spacing, gint column_spacing);

void add_stack(GtkWidget *grid, GtkWidget *widget, gint row, gint column, gint row_span, gint col_span);

void set_column_width(GtkWidget *grid, gint column, gint width);

Tool	*criar_txt();

void set_row_height(GtkWidget *grid, gint row, gint height);

void set_row_spacing(GtkWidget *grid, gint spacing);

void set_column_spacing(GtkWidget *grid, gint spacing);

void configure_expand_fill(GtkWidget *widget, gboolean expand, gboolean fill);

void setbackground_color(GtkWidget *widget, const gchar *color_hex);

void add_label_to_grid(GtkWidget *grid, GtkWidget *label, gint row, gint column, gint row_span, gint col_span);

void add_button_to_grid(GtkWidget *grid, GtkWidget *button, gint row, gint column, gint row_span, gint col_span);

GtkWidget* create_label_with_text(const gchar *text);

GtkWidget* create_button_with_text(const gchar *text, GCallback callback, gpointer user_data);

void set_grid_spacing(GtkWidget *grid, guint row_spacing, guint column_spacing);

void add_box_to_grid(GtkWidget *grid, GtkWidget *box, gint row, gint column, gint row_span, gint col_span);

void remove_widget_from_grid(GtkWidget *grid, GtkWidget *widget);

void set_widget_expand_fill(GtkWidget *widget, gboolean expand, gboolean fill);

void set_widget_alignment(GtkWidget *widget, GtkAlign halign, GtkAlign valign);

void set_grid_row_column_size(GtkWidget *grid, guint row, guint column, gint row_height, gint column_width);

GtkWidget* create_and_configure_grid(gint rows, gint columns, guint row_spacing, guint column_spacing);

GtkWidget* create_mo_configure_grid(gint rows, gint columns, guint row_spacing, guint column_spacing);

GtkWidget* create_grid_container(GtkWidget *container);

GtkWidget* create_and_add_button_with_text_and_image(GtkWidget *grid, const gchar *text, const gchar *image_path, gint column, gint row, gint colspan, gint rowspan, GCallback on_clicked);

GtkWidget* create_and_add_button_with_image(GtkWidget *grid, const gchar *image_path, gint column, gint row, gint colspan, gint rowspan, GCallback on_clicked);

GtkWidget* create_and_add_list_with_items(GtkWidget *grid, const gchar *items[], gint num_items, gint column, gint row, gint colspan, gint rowspan);

GtkWidget* create_and_add_image(GtkWidget *grid, const gchar *image_path, gint column, gint row, gint colspan, gint rowspan);

GtkWidget* create_and_add_header(GtkWidget *grid, const gchar *text, gint column, gint row, gint colspan, gint rowspan);

void set_column_widths(GtkWidget *grid, gint width, gint num_columns);

void set_row_heights(GtkWidget *grid, gint height, gint num_rows);

GtkWidget* create_and_add_button_with_text(GtkWidget *grid, const gchar *text, gint column, gint row, gint colspan, gint rowspan, GCallback on_clicked);

void set_all_column_widths(GtkWidget *grid, gint width);

void set_all_row_heights(GtkWidget *grid, gint height);

GtkWidget* create_and_add_label(GtkWidget *grid, const gchar *text, gint left, gint top, gint width, gint height);

// Cria uma imagem e a adiciona ao grid, retornando a imagem criada
//GtkWidget* create_and_add_image(GtkWidget *grid, const gchar *image_path, gint left, gint top, gint width, gint height);

// Cria um campo de entrada (entry) e o adiciona ao grid, retornando o campo de entrada criado
GtkWidget* create_and_add_entry(GtkWidget *grid, gint left, gint top, gint width, gint height);

void add_label_list_to_grid(GtkWidget *grid, GList *label_list, gint start_column, gint start_row);

GList* create_label_list(const gchar **data, gint num_items);

GtkWidget* create_vbox(gboolean homogeneous, gint spacing);

void add_widget_to_vbox_start(GtkWidget *vbox, GtkWidget *widget, gboolean expand, gboolean fill, gint padding);

void add_widget_to_vbox_end(GtkWidget *vbox, GtkWidget *widget, gboolean expand, gboolean fill, gint padding);

GtkWidget* create_terminal(const gchar *initial_command);

void set_terminal_command(GtkWidget *terminal, const gchar *command);

GtkWidget* create_button_with_text_vbox(const gchar *label, GCallback callback, gpointer user_data);

GtkWidget* create_text_entry_vbox(const gchar *placeholder_text, gboolean is_editable);

GtkWidget* create_combo_box_with_items_vbox(const gchar *items[], gint item_count);

GtkWidget* create_check_box_vbox(const gchar *label, gboolean initial_state);

GtkWidget* create_radio_button_vbox(const gchar *label, GSList *group);

GtkWidget* create_label_with_text_vbox(const gchar *text);

GtkWidget* create_progress_bar_vbox(void);

GtkWidget* create_text_view_with_content_vbox(const gchar *text);

GtkWidget* create_file_chooser_button_vbox(const gchar *title);

GtkWidget* create_color_button_vbox(GdkRGBA *initial_color);


void	printh(GtkWidget *wg, const char *main_name, const char *files);
t_element	*create_widget_hierarchy(GtkWidget *widget, const char *parent_name);
void	save_hierarchy(t_element *head, FILE *file, int depth);
void	free_hierarchy(t_element *head);










#endif
