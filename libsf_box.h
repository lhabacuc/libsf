#ifndef libsf_box_h
# define libsf_box_h
#include <stdbool.h>

#define new_notebook(parent_box, expand, fill, padding, spacing) ({   \
    GtkWidget *notebook = gtk_notebook_new();                        \
    gtk_box_set_spacing(GTK_BOX(parent_box), spacing);               \
    gtk_box_pack_start(GTK_BOX(parent_box), notebook, expand, fill, padding); \
    notebook;                                                        \
})

#define add_to_header_start(h, b) gtk_header_bar_pack_start(h, b)
#define add_to_header_end(h, b) gtk_header_bar_pack_end(h, b)
#define TopBar GtkHeaderBar

#define opacity(a, b) gtk_widget_set_opacity(a, b)

#define set_object_data(obj, key, value) g_object_set_data(G_OBJECT(obj), key, value);

#define get_object_data(obj, key) g_object_set_data(G_OBJECT(obj), key);
/*
GtkWidget *button;
set_object(button, "box2", box2);
GtkWidget *retrieved_box2 = get_object(button, "box2");
*/


#define visivel_get(a) gtk_widget_get_visible(a)

#define tab_inicial(notebook, aba_inicial) \
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), aba_inicial)


#define adicionar_aba(notebook, content, titulo) ({                        \
    GtkWidget *tab_label = gtk_label_new(titulo);                          \
    sf_set_name(tab_label, "tab_label");				   \
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content, tab_label);  \
})

#define adicionar_aba_s(notebook, content, titulo, fonte, cor_fonte, icone, espac_h, espac_v) ({ \
    GtkWidget *tab_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, espac_h);      \
    GtkWidget *tab_icon = gtk_image_new_from_icon_name(icone, GTK_ICON_SIZE_MENU); \
    GtkWidget *tab_label = gtk_label_new(titulo);                               \
    sf_set_name(tab_label, "tab_label");                                        \
    gtk_widget_set_name(tab_label, "custom_tab_label");                         \
                                                                                 \
    /* Estilizando o label */                                                    \
    gchar *css_data = g_strdup_printf(                                           \
        "#custom_tab_label { font-family: '%s'; color: '%s'; padding: %dpx %dpx; }", \
        fonte, cor_fonte, espac_v, espac_h);                                     \
    GtkCssProvider *css_provider = gtk_css_provider_new();                       \
    gtk_css_provider_load_from_data(css_provider, css_data, -1, NULL);                 \
    GtkStyleContext *style_context = gtk_widget_get_style_context(tab_label);    \
    gtk_style_context_add_provider(style_context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER); \
                                                                                 \
    /* Adicionando o ícone e o título ao contêiner com espaçamentos */           \
    if (icone)                                                                   \
        gtk_box_pack_start(GTK_BOX(tab_box), tab_icon, FALSE, FALSE, espac_h);    \
    gtk_box_pack_start(GTK_BOX(tab_box), tab_label, TRUE, TRUE, espac_v);        \
                                                                                 \
    /* Adiciona a aba ao notebook */                                             \
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content, tab_box);          \
    g_free(css_data);                                                            \
})



#define set_tab_pos(notebook, i) do {                   \
    GtkPositionType position;                          \
                                                        \
    switch (i) {                                       \
        case 0:                                         \
            position = GTK_POS_TOP;                    \
            break;                                     \
        case 1:                                         \
            position = GTK_POS_RIGHT;                  \
            break;                                     \
        case 2:                                         \
            position = GTK_POS_LEFT;                   \
            break;                                     \
        case 4:                                         \
            position = GTK_POS_BOTTOM;                 \
            break;                                     \
        default:                                        \
            position = GTK_POS_TOP;                    \
            break;                                     \
    }                                                   \
                                                        \
    gtk_notebook_set_tab_pos(notebook, position);       \
} while (0)


void	manipular_icone(GtkWidget *botao, const char *icone_caminho, 
								int largura_icone, int altura_icone, 
								int margem_esq, int margem_dir, 
								int margem_topo, int margem_baixo,
								gboolean redimensionar_automatico, 
								gboolean mostrar);

void	add_to_start(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding);

void	add_to_end(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding);

void add_box_to_box(GtkWidget *parent_box, GtkWidget *child_box, gboolean expand, gboolean fill, guint padding);

TopBar* create_top_bar(GtkWidget *window, const gchar *title, gboolean show_close_button);

void configure_box_spacing(GtkWidget *box, gint spacing);

GtkWidget* create_horizontal_box(gint spacing);

GtkWidget* create_vertical_box(gint spacing);

// Função personalizada para empacotar um widget em uma GtkBox
void	pack_box(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding);
// Função personalizada para adicionar um widget a um container
void	add_to_container(GtkWidget *container, GtkWidget *widget);

GtkWidget* create_box(int orientation, gint spacing);

GtkWidget*	create_separator_box(int orientation);
// tamanho set
void	set_size_box(GtkWidget *box_item, gint width, gint height);
// Cria uma lista (list box) com tamanho personalizado
GtkWidget *create_list(int width, int height);

// Adiciona um item à lista
void add_to_list(GtkWidget *list_box, GtkWidget *app_item);

// Exibe a lista dentro da janela
void show_box(Tool *win, Tool *list);

// Cria uma linha (box) com espaçamento
GtkWidget *line_to_list(int spacing);

// Cria um botão em uma linha com texto e callback
void create_button_line(GtkWidget *row, const char *label_text, GCallback callback, gpointer data, bool expand, bool fill, int padding);

// Cria uma imagem em uma linha
void create_image_line(GtkWidget *row, const char *image_path, bool expand, bool fill, int padding);

// Cria um rótulo em uma linha
void create_label_line(GtkWidget *row, const char *label_text, bool expand, bool fill, int padding);

// Cria uma entrada de texto em uma linha
void create_entry_line(GtkWidget *row, const char *placeholder_text, bool expand, bool fill, int padding);

// Cria uma caixa de seleção (combo box) em uma linha
void create_combobox_line(GtkWidget *row, const char *items[], int item_count, GCallback callback, gpointer data, bool expand, bool fill, int padding);

// Cria um botão de seleção (check button) em uma linha
void create_checkbutton_line(GtkWidget *row, const char *label_text, GCallback callback, gpointer data, bool expand, bool fill, int padding);

// Cria um botão de link
GtkWidget *create_link_button_box(const char *label, const char *uri);

// Cria uma área de texto (text view) com texto inicial
GtkWidget *create_text_view_box(const char *initial_text);

// Cria uma barra de rolagem (scrollbar) com um widget associado
GtkWidget *create_scrolled_window_box(GtkWidget *child);

// Cria uma caixa de seleção (combo box) com uma lista de opções
GtkWidget *create_combo_box_box(const char *items[], int item_count);

// Cria uma caixa de diálogo (dialog) com um título e uma mensagem
GtkWidget *create_dialog_box(const char *title, const char *message);

// Cria um botão com uma imagem e callback
GtkWidget *create_image_button_box(const char *file_path, GtkCallback callback, gpointer user_data);

// Cria um ajuste (spinner) com valores mínimo, máximo e inicial
GtkWidget *create_adjustment_box(double lower, double upper, double step, double initial);

// Cria uma barra de progresso
GtkWidget *create_progress_bar_box();

// Cria um botão de opção (radio button) dentro de um grupo
GtkWidget *create_radio_button_box(GtkWidget *group, const char *label);

// Cria um botão com um rótulo e callback
GtkWidget *create_button_box(const char *label, GtkCallback callback, gpointer user_data);

// Cria um rótulo de texto
GtkWidget *create_label_box(const char *text);

// Cria uma entrada de texto com texto placeholder
GtkWidget *create_entry_box(const char *placeholder);

// Cria uma imagem a partir de um arquivo
GtkWidget *create_image_box(const char *file_path);

// Cria uma caixa (box) com orientação e espaçamento personalizados
GtkWidget *create_box_box(GtkOrientation orientation, int spacing);

// Cria um botão de link
GtkWidget *create_link_button_box(const char *label, const char *uri);

// Cria uma área de texto (text view) com texto inicial
GtkWidget *create_text_view_box(const char *initial_text);

// Cria uma barra de rolagem (scrollbar) com um widget associado
GtkWidget *create_scrolled_window_box(GtkWidget *child);

// Cria uma caixa de seleção (combo box) com uma lista de opções
GtkWidget *create_combo_box_box(const char *items[], int item_count);

// Cria uma caixa de diálogo (dialog) com um título e uma mensagem
GtkWidget *create_dialog_box(const char *title, const char *message);

// Cria uma caixa de texto (text entry) com um texto inicial
GtkWidget *create_text_entry_box(const char *initial_text);

// Cria uma caixa de seleção (check button) com um rótulo e estado inicial
GtkWidget *create_check_button_box(const char *label, gboolean active);

// Cria um botão de rádio (radio button) dentro de um grupo
GtkWidget *create_radio_button_box(GtkWidget *group, const char *label);

// Cria uma barra de status (status bar)
GtkWidget *create_status_bar_box();

// Cria uma barra de rolagem vertical
GtkWidget *create_vertical_scrollbar_box();

// Cria uma barra de rolagem horizontal
GtkWidget *create_horizontal_scrollbar_box();

// Cria um botão de exibição (toggle button)
GtkWidget *create_toggle_button_box(const char *label);

// Cria uma caixa (box) com espaçamento personalizado
GtkWidget *create_custom_box_box(GtkOrientation orientation, int spacing, gboolean homogeneous);

// Cria um botão de imagem com tooltip
GtkWidget *create_image_button_tol_box(const char *image_path, const char *tooltip);

// Cria um botão com ícone e rótulo
GtkWidget *create_icon_button_box(const char *icon_name, const char *label);

// Cria uma área de desenho (drawing area)
GtkWidget *create_drawing_area_box();

// Cria um botão de alternância com ícone
GtkWidget *create_icon_toggle_button_box(const char *icon_name);

// Cria uma caixa de botão com tamanho fixo
GtkWidget *create_fixed_button_box(const char *label, int width, int height);

// Cria uma caixa de botão com várias linhas
GtkWidget *create_multiline_button_box(const char *label);

// Cria uma caixa de botão com uma imagem e texto abaixo
GtkWidget *create_image_below_text_button_box(const char *image_path, const char *text);

// Cria um botão de ação (action button)
GtkWidget *create_action_button_box(const char *label, GCallback callback, gpointer data);
// Cria um botão com uma imagem e um rótulo
GtkWidget *create_image_and_label_button_box(const char *image_path, const char *label);

// Cria uma caixa de botão com múltiplos ícones
GtkWidget *create_multiple_icon_button_box(const char *icon_names[], int icon_count);

// Cria uma caixa de botão com uma imagem e um rótulo centralizado
GtkWidget *create_centered_image_and_label_button_box(const char *image_path, const char *label);

// Cria uma caixa de texto com uma borda
GtkWidget *create_bordered_text_view_box(const char *initial_text);

// Cria uma caixa de seleção (combo box) com um rótulo
GtkWidget *create_labeled_combo_box_box(const char *label_text, const char *items[], int item_count);

// Cria uma caixa de seleção (check button) com rótulo e tooltip
GtkWidget *create_tooltip_check_button_box(const char *label, const char *tooltip);

// Cria uma caixa de seleção (combo box) com uma lista de opções e tooltip
GtkWidget *create_tooltip_combo_box_box(const char *items[], int item_count, const char *tooltip);

// Cria uma barra de progresso com um valor inicial
GtkWidget *create_progress_bar_with_value_box(double initial_value);

// Cria uma caixa de botão com um ícone, rótulo e tooltip
GtkWidget *create_icon_label_button_with_tooltip_box(const char *icon_name, const char *label, const char *tooltip);


#endif
