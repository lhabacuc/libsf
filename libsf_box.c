
#include "libsf.h"

TopBar* create_top_bar(GtkWidget *window, const gchar *title, gboolean show_close_button)
{
	TopBar *header_bar = GTK_HEADER_BAR(gtk_header_bar_new());
	gtk_header_bar_set_title(header_bar, title);
	gtk_header_bar_set_show_close_button(header_bar, show_close_button);
	gtk_window_set_titlebar(GTK_WINDOW(window), GTK_WIDGET(header_bar));
	return (header_bar);
}


GtkWidget	*create_list(int width, int height)
{
	GtkWidget *list_box = gtk_list_box_new();
	gtk_list_box_set_selection_mode(GTK_LIST_BOX(list_box), GTK_SELECTION_NONE);
	if (height && width)
		gtk_widget_set_size_request(list_box, width, height);
	return (list_box);
}

// Função para adicionar um widget no início de uma GtkBox
void	add_to_start(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding)
{
	gtk_box_pack_start(GTK_BOX(box), widget, expand, fill, padding);
}

// Função para adicionar um widget no final de uma GtkBox
void	add_to_end(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding)
{
	gtk_box_pack_end(GTK_BOX(box), widget, expand, fill, padding);
}


// Função para criar uma GtkBox
GtkWidget* create_box(int orientation, gint spacing)
{
	GtkOrientation gtk_orientation = (orientation == 1) ? GTK_ORIENTATION_HORIZONTAL : GTK_ORIENTATION_VERTICAL;
	GtkWidget *box = gtk_box_new(gtk_orientation, spacing);
	return box;
}

// Função personalizada para adicionar um widget a um container
void	add_to_container(GtkWidget *container, GtkWidget *widget)
{
	gtk_container_add(GTK_CONTAINER(container), widget);
}

// Função personalizada para empacotar um widget em uma GtkBox
void	pack_box(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding)
{
	gtk_box_pack_start(GTK_BOX(box), widget, expand, fill, padding);
}

// Função para criar uma GtkBox vertical
GtkWidget* create_vertical_box(gint spacing) {
    return gtk_box_new(GTK_ORIENTATION_VERTICAL, spacing);
}


// Função para criar uma GtkBox horizontal
GtkWidget* create_horizontal_box(gint spacing) {
    return gtk_box_new(GTK_ORIENTATION_HORIZONTAL, spacing);
}


// Função para definir o espaçamento entre widgets em uma GtkBox
void configure_box_spacing(GtkWidget *box, gint spacing) {
    gtk_box_set_spacing(GTK_BOX(box), spacing);
}


// Função para adicionar uma GtkBox a outra GtkBox
void add_box_to_box(GtkWidget *parent_box, GtkWidget *child_box, gboolean expand, gboolean fill, guint padding) {
    gtk_box_pack_start(GTK_BOX(parent_box), child_box, expand, fill, padding);
}


GtkWidget*	create_separator_box(int orientation)
{
	GtkOrientation gtk_orientation = (orientation == 1) ? GTK_ORIENTATION_HORIZONTAL : GTK_ORIENTATION_VERTICAL;
	GtkWidget *separator = gtk_separator_new(gtk_orientation);
	return separator;
}

void	add_to_list(GtkWidget *list_box, GtkWidget *app_item)
{
	gtk_list_box_insert(GTK_LIST_BOX(list_box), app_item, -1);
}

void	show_box(Tool *win, Tool *list)
{
	 gtk_container_add(GTK_CONTAINER(win), list);
}

GtkWidget	*line_to_list(int spacing)
{
	return gtk_box_new(GTK_ORIENTATION_HORIZONTAL, spacing);
}

void	create_button_line(GtkWidget *row, const char *label_text, GCallback callback, gpointer data, bool expand, bool fill, int padding)
{
	GtkWidget *button = gtk_button_new_with_label(label_text);
	g_signal_connect(button, "clicked", callback, data);
	gtk_box_pack_start(GTK_BOX(row), button, expand, fill, padding);
}

void	create_image_line(GtkWidget *row, const char *image_path, bool expand, bool fill, int padding)
{
	GtkWidget *image = gtk_image_new_from_file(image_path);
	gtk_box_pack_start(GTK_BOX(row), image, expand, fill, padding);
}

void	create_label_line(GtkWidget *row, const char *label_text, bool expand, bool fill, int padding)
{
	GtkWidget *label = gtk_label_new(label_text);
	gtk_box_pack_start(GTK_BOX(row), label, expand, fill, padding);
}

void	create_entry_line(GtkWidget *row, const char *placeholder_text, bool expand, bool fill, int padding)
{
	GtkWidget *entry = gtk_entry_new();
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholder_text);
	gtk_box_pack_start(GTK_BOX(row), entry, expand, fill, padding);
}

void	create_combobox_line(GtkWidget *row, const char *items[], int item_count, GCallback callback, gpointer data, bool expand, bool fill, int padding)
{
	GtkWidget *combobox = gtk_combo_box_text_new();
	for (int i = 0; i < item_count; i++)
	{
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), items[i]);
	}
	g_signal_connect(combobox, "changed", callback, data);
	gtk_box_pack_start(GTK_BOX(row), combobox, expand, fill, padding);
}

void	create_checkbutton_line(GtkWidget *row, const char *label_text, GCallback callback, gpointer data, bool expand, bool fill, int padding)
{
	GtkWidget *checkbutton = gtk_check_button_new_with_label(label_text);
	g_signal_connect(checkbutton, "toggled", callback, data);
	gtk_box_pack_start(GTK_BOX(row), checkbutton, expand, fill, padding);
}

// Função para criar um botão de link
GtkWidget *create_link_button_box(const char *label, const char *uri)
{
    GtkWidget *link_button;// = gtk_link_button_new(uri, label);
    return link_button;
}

// Função para criar uma barra de rolagem (scrollbar) com um widget associado
GtkWidget *create_scrolled_window_box(GtkWidget *child)
{
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolled_window), child);
    return scrolled_window;
}

// Função para criar uma caixa de seleção (combo box) com uma lista de opções
GtkWidget *create_combo_box_box(const char *items[], int item_count)
{
    GtkWidget *combo_box = gtk_combo_box_text_new();
    for (int i = 0; i < item_count; i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), items[i]);
    }
    return combo_box;
}

// Função para criar uma caixa de diálogo (dialog) com um título e uma mensagem
GtkWidget *create_dialog_box(const char *title, const char *message)
{
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", message);
    gtk_window_set_title(GTK_WINDOW(dialog), title);
    return dialog;
}

// Função para criar um botão com uma imagem
GtkWidget *create_image_button_box(const char *file_path, GtkCallback callback, gpointer user_data)
{
    GtkWidget *image = gtk_image_new_from_file(file_path);
    GtkWidget *button = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(button), image);
    g_signal_connect(button, "clicked", callback, user_data);
    return button;
}

// Função para criar um ajuste (spinner) com valores mínimo, máximo e inicial
GtkWidget *create_adjustment_box(double lower, double upper, double step, double initial)
{
    GtkWidget *adjustment = gtk_adjustment_new(initial, lower, upper, step, step, 0);
    GtkWidget *spin_button = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment), step, 0);
    return spin_button;
}

// Função para criar uma barra de progresso
GtkWidget *create_progress_bar_box()
{
    GtkWidget *progress_bar = gtk_progress_bar_new();
    return progress_bar;
}

// Função para criar um botão com um rótulo
GtkWidget *create_button_box(const char *label, GtkCallback callback, gpointer user_data)
{
    GtkWidget *button = gtk_button_new_with_label(label);
    g_signal_connect(button, "clicked", callback, user_data);
    return button;
}

// Função para criar um rótulo de texto
GtkWidget *create_label_box(const char *text)
{
    GtkWidget *label = gtk_label_new(text);
    sf_set_name(label, "label");
    return label;
}

// Função para criar uma entrada de texto
GtkWidget *create_entry_box(const char *placeholder)
{
    GtkWidget *entry = gtk_entry_new();
    if (placeholder)
        gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholder);
    return entry;
}

// Função para criar uma imagem a partir de um arquivo
GtkWidget *create_image_box(const char *file_path)
{
    GtkWidget *image = gtk_image_new_from_file(file_path);
    return image;
}

// Função para criar uma caixa com widgets filhos
GtkWidget *create_box_box(GtkOrientation orientation, int spacing)
{
    GtkWidget *box = gtk_box_new(orientation, spacing);
    return box;
}

// Função para criar uma área de texto (text view)
GtkWidget *create_text_view_box(const char *initial_text)
{
    GtkWidget *text_view = gtk_text_view_new();
    if (initial_text)
    {
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
        gtk_text_buffer_set_text(buffer, initial_text, -1);
    }
    return text_view;
}

// Função para criar uma caixa de texto (text entry) com um texto inicial
GtkWidget *create_text_entry_box(const char *initial_text)
{
    GtkWidget *entry = gtk_entry_new();
    if (initial_text)
    {
        gtk_entry_set_text(GTK_ENTRY(entry), initial_text);
    }
    return entry;
}

// Função para criar uma caixa de seleção (check button) com um rótulo e estado inicial
GtkWidget *create_check_button_box(const char *label, gboolean active)
{
    GtkWidget *check_button = gtk_check_button_new_with_label(label);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_button), active);
    return check_button;
}

// Função para criar um botão de rádio (radio button) dentro de um grupo
GtkWidget *create_radio_button_box(GtkWidget *group, const char *label)
{
    GtkWidget *radio_button = gtk_radio_button_new_with_label(GTK_RADIO_BUTTON(group), label);
    return radio_button;
}

// Função para criar uma barra de status (status bar)
GtkWidget *create_status_bar_box()
{
    GtkWidget *status_bar = gtk_statusbar_new();
    return status_bar;
}

// Função para criar uma barra de rolagem vertical
GtkWidget *create_vertical_scrollbar_box()
{
    GtkWidget *scrollbar = gtk_scrollbar_new(GTK_ORIENTATION_VERTICAL, NULL);
    return scrollbar;
}

// Função para criar uma barra de rolagem horizontal
GtkWidget *create_horizontal_scrollbar_box()
{
    GtkWidget *scrollbar = gtk_scrollbar_new(GTK_ORIENTATION_HORIZONTAL, NULL);
    return scrollbar;
}

// Função para criar um botão de exibição (toggle button)
GtkWidget *create_toggle_button_box(const char *label)
{
    GtkWidget *toggle_button = gtk_toggle_button_new_with_label(label);
    return toggle_button;
}

// Função para criar uma caixa (box) com espaçamento personalizado
GtkWidget *create_custom_box_box(GtkOrientation orientation, int spacing, gboolean homogeneous)
{
    GtkWidget *box = gtk_box_new(orientation, spacing);
    gtk_box_set_homogeneous(GTK_BOX(box), homogeneous);
    return box;
}


// Função para criar um botão de imagem
GtkWidget *create_image_button_tol_box(const char *image_path, const char *tooltip)
{
    GtkWidget *image = gtk_image_new_from_file(image_path);
    GtkWidget *button = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(button), image);
    if (tooltip)
    {
        gtk_widget_set_tooltip_text(button, tooltip);
    }
    return button;
}

// Função para criar um botão com ícone e rótulo
GtkWidget *create_icon_button_box(const char *icon_name, const char *label)
{
    GtkWidget *button = gtk_button_new();
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *icon = gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_BUTTON);
    GtkWidget *label_widget = gtk_label_new(label);
    gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_widget, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(button), box);
    return button;
}

// Função para criar uma área de desenho (drawing area)
GtkWidget *create_drawing_area_box()
{
    GtkWidget *drawing_area = gtk_drawing_area_new();
    return drawing_area;
}

// Função para criar um botão de alternância com ícone
GtkWidget *create_icon_toggle_button_box(const char *icon_name)
{
    GtkWidget *button = gtk_toggle_button_new();
    GtkWidget *icon = gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_BUTTON);
    gtk_button_set_image(GTK_BUTTON(button), icon);
    return button;
}

// Função para criar uma caixa de botão com tamanho fixo
GtkWidget *create_fixed_button_box(const char *label, int width, int height)
{
    GtkWidget *button = gtk_button_new_with_label(label);
    gtk_widget_set_size_request(button, width, height);
    return button;
}

// Função para criar uma caixa de botão com várias linhas
GtkWidget *create_multiline_button_box(const char *label)
{
    GtkWidget *button = gtk_button_new();
    GtkWidget *label_widget = gtk_label_new(label);
    gtk_label_set_line_wrap(GTK_LABEL(label_widget), TRUE);
    gtk_button_set_label(GTK_BUTTON(button), NULL);
    gtk_container_add(GTK_CONTAINER(button), label_widget);
    return button;
}

// Função para criar uma caixa de botão com uma imagem e texto abaixo
GtkWidget *create_image_below_text_button_box(const char *image_path, const char *text)
{
    GtkWidget *button = gtk_button_new();
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *image = gtk_image_new_from_file(image_path);
    GtkWidget *label = gtk_label_new(text);
    gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(button), box);
    return button;
}

// Função para criar um botão de ação (action button)
GtkWidget *create_action_button_box(const char *label, GCallback callback, gpointer data)
{
    GtkWidget *button = gtk_button_new_with_label(label);
    g_signal_connect(button, "clicked", callback, data);
    return button;
}

// Função para criar um botão com uma imagem e um rótulo
GtkWidget *create_image_and_label_button_box(const char *image_path, const char *label)
{
    GtkWidget *button = gtk_button_new();
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *image = gtk_image_new_from_file(image_path);
    GtkWidget *label_widget = gtk_label_new(label);
    gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_widget, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(button), box);
    return button;
}

// Função para criar uma caixa de botão com múltiplos ícones
GtkWidget *create_multiple_icon_button_box(const char *icon_names[], int icon_count)
{
    GtkWidget *button = gtk_button_new();
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    for (int i = 0; i < icon_count; i++)
    {
        GtkWidget *icon = gtk_image_new_from_icon_name(icon_names[i], GTK_ICON_SIZE_BUTTON);
        gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);
    }
    gtk_container_add(GTK_CONTAINER(button), box);
    return button;
}

// Função para criar uma caixa de botão com uma imagem e um rótulo centralizado
GtkWidget *create_centered_image_and_label_button_box(const char *image_path, const char *label)
{
    GtkWidget *button = gtk_button_new();
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *image = gtk_image_new_from_file(image_path);
    GtkWidget *label_widget = gtk_label_new(label);
    gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_widget, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(button), box);
    return button;
}

// Função para criar uma caixa de texto com uma borda
GtkWidget *create_bordered_text_view_box(const char *initial_text)
{
    GtkWidget *text_view = gtk_text_view_new();
    GtkWidget *frame = gtk_frame_new(NULL);
    gtk_container_add(GTK_CONTAINER(frame), text_view);
    gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_ETCHED_IN);
    if (initial_text)
    {
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
        gtk_text_buffer_set_text(buffer, initial_text, -1);
    }
    return frame;
}

// Função para criar uma caixa de seleção (combo box) com um rótulo
GtkWidget *create_labeled_combo_box_box(const char *label_text, const char *items[], int item_count)
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *label = gtk_label_new(label_text);
    GtkWidget *combo_box = gtk_combo_box_text_new();
    for (int i = 0; i < item_count; i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), items[i]);
    }
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), combo_box, FALSE, FALSE, 0);
    return box;
}

// Função para criar uma caixa de seleção (check button) com rótulo e tooltip
GtkWidget *create_tooltip_check_button_box(const char *label, const char *tooltip)
{
    GtkWidget *check_button = gtk_check_button_new_with_label(label);
    if (tooltip)
    {
        gtk_widget_set_tooltip_text(check_button, tooltip);
    }
    return check_button;
}

// Função para criar uma caixa de seleção (combo box) com uma lista de opções e tooltip
GtkWidget *create_tooltip_combo_box_box(const char *items[], int item_count, const char *tooltip)
{
    GtkWidget *combo_box = gtk_combo_box_text_new();
    for (int i = 0; i < item_count; i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), items[i]);
    }
    if (tooltip)
    {
        gtk_widget_set_tooltip_text(combo_box, tooltip);
    }
    return combo_box;
}

Tool	*button_s(char *text)
{
	//sf_set_name(button, "button");
	return (gtk_button_new_with_label(text));
}

// Função para criar uma barra de progresso com um valor inicial
GtkWidget *create_progress_bar_with_value_box(double initial_value)
{
    GtkWidget *progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), initial_value);
    return progress_bar;
}

// Função para criar uma caixa de botão com um ícone, rótulo e tooltip
GtkWidget *create_icon_label_button_with_tooltip_box(const char *icon_name, const char *label, const char *tooltip)
{
    GtkWidget *button = gtk_button_new();
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *icon = gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_BUTTON);
    GtkWidget *label_widget = gtk_label_new(label);
    gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_widget, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(button), box);
    if (tooltip)
    {
        gtk_widget_set_tooltip_text(button, tooltip);
    }
    return button;
}

void	set_size_box(GtkWidget *box_item, gint width, gint height)
{
	if (GTK_IS_WIDGET(box_item))
		gtk_widget_set_size_request(box_item, width, height);
}

void	manipular_icone(GtkWidget *botao, const char *icone_caminho, 
								int largura_icone, int altura_icone, 
								int margem_esq, int margem_dir, 
								int margem_topo, int margem_baixo,
								gboolean redimensionar_automatico, 
								gboolean mostrar)
{
	GList		*children;
	GtkWidget	*imagem;
	GtkWidget	*caixa;

	children = gtk_container_get_children(GTK_CONTAINER(botao));
	for (GList *iter = children; iter != NULL; iter = iter->next)
	{
		if (GTK_IS_IMAGE(iter->data))
			gtk_widget_destroy(GTK_WIDGET(iter->data));
	}
	g_list_free(children);

	imagem = gtk_image_new_from_file(icone_caminho);
	if (redimensionar_automatico)
		gtk_image_set_pixel_size(GTK_IMAGE(imagem), largura_icone);

	gtk_widget_set_size_request(imagem, largura_icone, altura_icone);

	gtk_widget_set_margin_start(botao, margem_esq);
	gtk_widget_set_margin_end(botao, margem_dir);
	gtk_widget_set_margin_top(botao, margem_topo);
	gtk_widget_set_margin_bottom(botao, margem_baixo);
	
	caixa = gtk_bin_get_child(GTK_BIN(botao));
	if (!caixa)
	{
		caixa = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
		gtk_container_add(GTK_CONTAINER(botao), caixa);
	}
	gtk_box_pack_start(GTK_BOX(caixa), imagem, FALSE, FALSE, 5);

	gtk_widget_set_visible(imagem, mostrar);

	sf_set_name(imagem, "imagem");
	sf_set_name(caixa, "box");
	gtk_widget_show_all(botao);
}
