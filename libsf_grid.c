#include "libsf_grid.h"
// Função para criar uma GtkGrid
GtkWidget* create_grid(gint row_spacing, gint column_spacing)
{
	GtkWidget *grid = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(grid), row_spacing);
	gtk_grid_set_column_spacing(GTK_GRID(grid), column_spacing);
	return grid;
}
Tool	*criar_txt()
{
	return gtk_text_view_new();
}

GtkWidget	*botton_icone(const char *icone_caminho, const char *texto,
				int largura, int altura, int margem, const char *tooltip)
{
	GtkWidget	*botao;
	GtkWidget	*imagem;
	GtkWidget	*caixa;

	botao = gtk_button_new();
	imagem = gtk_image_new_from_file(icone_caminho);
	caixa = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

	gtk_box_pack_start(GTK_BOX(caixa), imagem, FALSE, FALSE, 5);
	if (texto)
	{
		GtkWidget	*label;
		label = gtk_label_new(texto);
		gtk_box_pack_start(GTK_BOX(caixa), label, FALSE, FALSE, 5);
	}
	gtk_container_add(GTK_CONTAINER(botao), caixa);

	// Definindo as propriedades
	gtk_widget_set_size_request(botao, largura, altura);
	gtk_widget_set_margin_start(botao, margem);
	gtk_widget_set_margin_end(botao, margem);
	gtk_widget_set_margin_top(botao, margem);
	gtk_widget_set_margin_bottom(botao, margem);

	// Definindo tooltip, se houver
	if (tooltip)
		gtk_widget_set_tooltip_text(botao, tooltip);

	return (botao);
}



// Função para adicionar um widget à grade
void add_stack(GtkWidget *grid, GtkWidget *widget, gint row, gint column, gint row_span, gint col_span)
{
	gtk_grid_attach(GTK_GRID(grid), widget, column, row, col_span, row_span);
}

// Função para definir o tamanho da coluna
void set_column_width(GtkWidget *grid, gint column, gint width)
{
	gtk_widget_set_size_request(gtk_grid_get_child_at(GTK_GRID(grid), column, 0), width, -1);
}

// Função para definir o tamanho da linha
void set_row_height(GtkWidget *grid, gint row, gint height)
{
	gtk_widget_set_size_request(gtk_grid_get_child_at(GTK_GRID(grid), 0, row), -1, height);
}

// Função para definir o espaçamento das linhas
void set_row_spacing(GtkWidget *grid, gint spacing)
{
	gtk_grid_set_row_spacing(GTK_GRID(grid), spacing);
}

// Função para definir o espaçamento das colunas
void set_column_spacing(GtkWidget *grid, gint spacing)
{
	gtk_grid_set_column_spacing(GTK_GRID(grid), spacing);
}

// Função para configurar expansão e preenchimento de um widget
void configure_expand_fill(GtkWidget *widget, gboolean expand, gboolean fill)
{
	gtk_widget_set_hexpand(widget, expand);
	gtk_widget_set_vexpand(widget, expand);
	gtk_widget_set_hexpand_set(widget, fill);
	gtk_widget_set_vexpand_set(widget, fill);
}

// Função para criar um botão com texto e callback
GtkWidget* create_button_with_text(const gchar *text, GCallback callback, gpointer user_data) {
    GtkWidget *button = gtk_button_new_with_label(text);
    g_signal_connect(button, "clicked", callback, user_data);
    return button;
}

// Função para criar um rótulo com texto
GtkWidget* create_label_with_text(const gchar *text) {
    GtkWidget *label = gtk_label_new(text);
    return label;
}

// Função para adicionar um botão à grade
void add_button_to_grid(GtkWidget *grid, GtkWidget *button, gint row, gint column, gint row_span, gint col_span) {
    gtk_grid_attach(GTK_GRID(grid), button, column, row, col_span, row_span);
}

// Função para adicionar um rótulo à grade
void add_label_to_grid(GtkWidget *grid, GtkWidget *label, gint row, gint column, gint row_span, gint col_span) {
    gtk_grid_attach(GTK_GRID(grid), label, column, row, col_span, row_span);
}

// Função para configurar a cor de fundo de um widget
void setbackground_color(GtkWidget *widget, const gchar *color_hex) {
    GdkRGBA color;
    gdk_rgba_parse(&color, color_hex);
    gtk_widget_override_background_color(widget, GTK_STATE_FLAG_NORMAL, &color);
}

// Função para definir o espaçamento entre linhas e colunas
void set_grid_spacing(GtkWidget *grid, guint row_spacing, guint column_spacing) {
    gtk_grid_set_row_spacing(GTK_GRID(grid), row_spacing);
    gtk_grid_set_column_spacing(GTK_GRID(grid), column_spacing);
}

// Função para adicionar uma caixa à grade
void add_box_to_grid(GtkWidget *grid, GtkWidget *box, gint row, gint column, gint row_span, gint col_span) {
    gtk_grid_attach(GTK_GRID(grid), box, column, row, col_span, row_span);
}

// Função para remover um widget da grade
void remove_widget_from_grid(GtkWidget *grid, GtkWidget *widget) {
    gtk_widget_destroy(widget);
}

// Função para ajustar a configuração de expandir e preencher
void set_widget_expand_fill(GtkWidget *widget, gboolean expand, gboolean fill) {
    gtk_widget_set_hexpand(widget, expand);
    gtk_widget_set_vexpand(widget, expand);
    gtk_widget_set_hexpand_set(widget, expand);
    gtk_widget_set_vexpand_set(widget, expand);
    gtk_widget_set_margin_start(widget, fill ? 0 : -1);
    gtk_widget_set_margin_end(widget, fill ? 0 : -1);
    gtk_widget_set_margin_top(widget, fill ? 0 : -1);
    gtk_widget_set_margin_bottom(widget, fill ? 0 : -1);
}

// Função para configurar as propriedades de alinhamento do widget
void set_widget_alignment(GtkWidget *widget, GtkAlign halign, GtkAlign valign) {
    gtk_widget_set_halign(widget, halign);
    gtk_widget_set_valign(widget, valign);
}

// Função para definir a largura e a altura de uma linha e coluna
void set_grid_row_column_size(GtkWidget *grid, guint row, guint column, gint row_height, gint column_width) {
    GtkWidget *row_widget = gtk_grid_get_child_at(GTK_GRID(grid), column, row);
    if (row_widget) {
        gtk_widget_set_size_request(row_widget, column_width, row_height);
    }
}

// Função para criar e configurar uma grade com espaçamento
GtkWidget* create_and_configure_grid(gint rows, gint columns, guint row_spacing, guint column_spacing) {
    GtkWidget *grid = gtk_grid_new(); // Cria a grade
    gtk_grid_set_row_spacing(GTK_GRID(grid), row_spacing); // Define o espaçamento entre linhas
    gtk_grid_set_column_spacing(GTK_GRID(grid), column_spacing); // Define o espaçamento entre colunas
    return grid;
}

// Função para criar e configurar uma grade com espaçamento
GtkWidget* create_mo_configure_grid(gint rows, gint columns, guint row_spacing, guint column_spacing) {
    GtkWidget *grid = gtk_grid_new(); // Cria a grade
    gtk_grid_set_row_spacing(GTK_GRID(grid), row_spacing);
    gtk_grid_set_column_spacing(GTK_GRID(grid), column_spacing); // Define o espaçamento entre colunas
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE); // Faz as linhas terem tamanho homogêneo
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE); // Faz as colunas terem tamanho homogêneo
    return grid;
}

GtkWidget* create_grid_container(GtkWidget *container) {
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(container), grid);
    return grid;
}

GtkWidget* create_and_add_button_with_text_and_image(GtkWidget *grid, const gchar *text, const gchar *image_path, gint column, gint row, gint colspan, gint rowspan, GCallback on_clicked) {
    GtkWidget *button = gtk_button_new();
    
    // Criar uma caixa para conter o texto e a imagem
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    
    // Criar e adicionar o texto
    GtkWidget *label = gtk_label_new(text);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    
    // Criar e adicionar a imagem
    GtkWidget *image = gtk_image_new_from_file(image_path);
    gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 0);
    
    gtk_container_add(GTK_CONTAINER(button), box);  // Define a caixa como o filho do botão
    
    if (on_clicked) {
        g_signal_connect(button, "clicked", on_clicked, NULL);
    }
    
    gtk_grid_attach(GTK_GRID(grid), button, column, row, colspan, rowspan);
    return button;
}


// Função para criar e adicionar um botão com imagem
GtkWidget* create_and_add_button_with_image(GtkWidget *grid, const gchar *image_path, gint column, gint row, gint colspan, gint rowspan, GCallback on_clicked) {
    GtkWidget *button = gtk_button_new();
    GtkWidget *image = gtk_image_new_from_file(image_path);
    gtk_button_set_image(GTK_BUTTON(button), image);  // Use gtk_button_set_image para adicionar imagem
    if (on_clicked) {
        g_signal_connect(button, "clicked", on_clicked, NULL);
    }
    gtk_grid_attach(GTK_GRID(grid), button, column, row, colspan, rowspan);
    return button;
}


// Cria uma lista com itens de texto e a adiciona à grid na posição especificada
GtkWidget* create_and_add_list_with_items(GtkWidget *grid, const gchar *items[], gint num_items, gint column, gint row, gint colspan, gint rowspan) {
    GtkWidget *list_box = gtk_list_box_new();
    for (gint i = 0; i < num_items; i++) {
        GtkWidget *label = gtk_label_new(items[i]);
        gtk_list_box_insert(GTK_LIST_BOX(list_box), label, -1);
    }
    gtk_grid_attach(GTK_GRID(grid), list_box, column, row, colspan, rowspan);
    return list_box;
}

// Cria uma imagem a partir de um caminho de arquivo e a adiciona à grid na posição especificada
GtkWidget* create_and_add_image(GtkWidget *grid, const gchar *image_path, gint column, gint row, gint colspan, gint rowspan) {
    GtkWidget *image = gtk_image_new_from_file(image_path);
    gtk_grid_attach(GTK_GRID(grid), image, column, row, colspan, rowspan);
    return image;
}

// Cria um cabeçalho com texto e o adiciona à grid na posição especificada
GtkWidget* create_and_add_header(GtkWidget *grid, const gchar *text, gint column, gint row, gint colspan, gint rowspan) {
    GtkWidget *header = gtk_label_new(text);
    gtk_widget_set_halign(header, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(header, GTK_ALIGN_CENTER);
    gtk_grid_attach(GTK_GRID(grid), header, column, row, colspan, rowspan);
    return header;
}

// Define a largura para todas as colunas na grid
void set_column_widths(GtkWidget *grid, gint width, gint num_columns) {
    for (gint i = 0; i < num_columns; i++) {
        GtkWidget *widget = gtk_grid_get_child_at(GTK_GRID(grid), i, 0);
        if (widget != NULL) {
            gtk_widget_set_size_request(widget, width, -1);
        }
    }
}

// Define a altura para todas as linhas na grid
void set_row_heights(GtkWidget *grid, gint height, gint num_rows) {
    for (gint i = 0; i < num_rows; i++) {
        GtkWidget *widget = gtk_grid_get_child_at(GTK_GRID(grid), 0, i);
        if (widget != NULL) {
            gtk_widget_set_size_request(widget, -1, height);
        }
    }
}

GtkWidget* create_and_add_button_with_text(GtkWidget *grid, const gchar *text, gint column, gint row, gint colspan, gint rowspan, GCallback on_clicked) {
    GtkWidget *button = gtk_button_new_with_label(text);
    
    if (on_clicked)
        g_signal_connect(button, "clicked", G_CALLBACK(on_clicked), NULL);
    
    gtk_grid_attach(GTK_GRID(grid), button, column, row, colspan, rowspan);
    return button;
}

void set_all_column_widths(GtkWidget *grid, gint width)
{
    gint i = 0;
    GtkWidget *child;
    
    while ((child = gtk_grid_get_child_at(GTK_GRID(grid), i, 0)) != NULL)
    {
        gtk_widget_set_size_request(child, width, -1);
        i++;
    }
}

void set_all_row_heights(GtkWidget *grid, gint height)
{
    gint i = 0;
    GtkWidget *child;
    
    while ((child = gtk_grid_get_child_at(GTK_GRID(grid), 0, i)) != NULL)
    {
        gtk_widget_set_size_request(child, -1, height);
        i++;
    }
}

GtkWidget* create_and_add_label(GtkWidget *grid, const gchar *text, gint left, gint top, gint width, gint height) {
    GtkWidget *label = gtk_label_new(text);
    gtk_grid_attach(GTK_GRID(grid), label, left, top, width, height);
    return label; // Retorna o rótulo criado
}

/*GtkWidget* create_and_add_image(GtkWidget *grid, const gchar *image_path, gint left, gint top, gint width, gint height) {
    GtkWidget *image = gtk_image_new_from_file(image_path);
    gtk_grid_attach(GTK_GRID(grid), image, left, top, width, height);
    return image; // Retorna a imagem criada
}
*/
GtkWidget* create_and_add_entry(GtkWidget *grid, gint left, gint top, gint width, gint height)
{
    GtkWidget *entry = gtk_entry_new();
    sf_set_name(entry, "entry");
    gtk_grid_attach(GTK_GRID(grid), entry, left, top, width, height);
    return entry; // Retorna o campo de entrada criado
}

// Função para criar uma lista de rótulos a partir de uma lista de dados
GList* create_label_list(const gchar **data, gint num_items)
{
    GList *label_list = NULL;

    for (gint i = 0; i < num_items; i++)
    {
        GtkWidget *label = gtk_label_new(data[i]);
        label_list = g_list_append(label_list, label);
    }

    return label_list;
}

// Função para adicionar uma lista de widgets a um GtkGrid
void add_label_list_to_grid(GtkWidget *grid, GList *label_list, gint start_column, gint start_row)
{
    GList *iter = NULL;
    gint column = start_column;
    gint row = start_row;

    for (iter = label_list; iter; iter = iter->next) {
        GtkWidget *widget = GTK_WIDGET(iter->data);
        gtk_grid_attach(GTK_GRID(grid), widget, column, row, 1, 1);
        row++;

        // Ajusta a coluna se a linha estiver cheia
        if (row >= 10) {  // Exemplo: Limita a 10 widgets por coluna
            row = start_row;
            column++;
        }
    }
}


// Função para criar um GtkVBox (GTK 3 utiliza GtkBox com orientação vertical)
GtkWidget* create_vbox(gboolean homogeneous, gint spacing)
{
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, spacing);
    gtk_box_set_homogeneous(GTK_BOX(vbox), homogeneous);
    return vbox;
}

// Função para adicionar um widget ao início do GtkVBox
void add_widget_to_vbox_start(GtkWidget *vbox, GtkWidget *widget, gboolean expand, gboolean fill, gint padding) {
    gtk_box_pack_start(GTK_BOX(vbox), widget, expand, fill, padding);
}

// Função para adicionar um widget ao final do GtkVBox
void add_widget_to_vbox_end(GtkWidget *vbox, GtkWidget *widget, gboolean expand, gboolean fill, gint padding) {
    gtk_box_pack_end(GTK_BOX(vbox), widget, expand, fill, padding);
}

// Função para criar um GtkTerminal (ou um widget similar, como GtkTextView para emulação de terminal)
GtkWidget* create_terminal(const gchar *initial_command)
{
    GtkWidget *terminal = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(terminal));
    gtk_text_buffer_set_text(buffer, initial_command, -1);
    return terminal;
}

// Função para configurar o GtkTerminal para um comando inicial
void set_terminal_command(GtkWidget *terminal, const gchar *command)
{
    if (GTK_IS_TEXT_VIEW(terminal)) {
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(terminal));
        gtk_text_buffer_set_text(buffer, command, -1);
    }
}

// Função para criar um botão com texto e uma ação de callback
GtkWidget* create_button_with_text_vbox(const gchar *label, GCallback callback, gpointer user_data)
{
    GtkWidget *button = gtk_button_new_with_label(label);
    g_signal_connect(button, "clicked", callback, user_data);
    return button;
}

// Função para criar uma entrada de texto com um texto de placeholder e configurável como editável
GtkWidget* create_text_entry_vbox(const gchar *placeholder_text, gboolean is_editable)
{
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholder_text);
    gtk_entry_set_tabs(GTK_ENTRY(entry), is_editable);
    return entry;
}

// Função para criar uma caixa de seleção (ComboBox) com itens
GtkWidget* create_combo_box_with_items_vbox(const gchar *items[], gint item_count)
{
    GtkWidget *combo_box = gtk_combo_box_text_new();
    for (gint i = 0; i < item_count; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), items[i]);
    }
    return combo_box;
}

// Função para criar uma caixa de seleção (CheckBox) com texto
GtkWidget* create_check_box_vbox(const gchar *label, gboolean initial_state)
{
    GtkWidget *check_box = gtk_check_button_new_with_label(label);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_box), initial_state);
    return check_box;
}

// Função para criar uma caixa de seleção (RadioButton) com texto e grupo
GtkWidget* create_radio_button_vbox(const gchar *label, GSList *group)
{
    GtkWidget *radio_button = gtk_radio_button_new_with_label(group, label);
    return radio_button;
}

// Função para criar um rótulo (Label) com texto
GtkWidget* create_label_with_text_vbox(const gchar *text)
{
    GtkWidget *label = gtk_label_new(text);
    return label;
}

// Função para criar uma caixa de progresso (ProgressBar)
GtkWidget* create_progress_bar_vbox(void)
{
    GtkWidget *progress_bar = gtk_progress_bar_new();
    return progress_bar;
}

// Função para criar uma área de texto (TextView) com texto inicial
GtkWidget* create_text_view_with_content_vbox(const gchar *text) {
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, text, -1);
    return text_view;
}

// Função para criar uma caixa de seleção de arquivo (FileChooserButton)
GtkWidget* create_file_chooser_button_vbox(const gchar *title) {
    GtkWidget *file_chooser_button = gtk_file_chooser_button_new(title, GTK_FILE_CHOOSER_ACTION_OPEN);
    return file_chooser_button;
}

// Função para criar uma caixa de seleção de cor (ColorButton) com uma cor inicial
GtkWidget* create_color_button_vbox(GdkRGBA *initial_color) {
    GtkWidget *color_button = gtk_color_button_new();
    gtk_color_button_set_rgba(GTK_COLOR_BUTTON(color_button), initial_color);
    return color_button;
}

void apply_css_f(GtkWidget *widget, const gchar *css) {
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    GtkStyleContext *style_context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(style_context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(css_provider);
}

void	apply_css_file(GtkWidget *widget, const gchar *css_file_path)
{
	GtkCssProvider *css_provider;
	GdkDisplay *display;
	GtkStyleContext *context;
	css_provider = gtk_css_provider_new();
	gtk_css_provider_load_from_file(css_provider, g_file_new_for_path(css_file_path), NULL);
	display = gdk_display_get_default();
	context = gtk_widget_get_style_context(widget);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);
}

t_element *create_widget_hierarchy(GtkWidget *widget, const char *parent_name)
{
	t_element *head = NULL;
	t_element *current = NULL;
	const gchar *name = gtk_widget_get_name(widget);
	t_element *element = malloc(sizeof(t_element));
	if (element == NULL)
		return NULL;
	strncpy(element->name, name ? name : "Unnamed", sizeof(element->name));
	strncpy(element->parent, parent_name, sizeof(element->parent));
	element->children = NULL;
	element->next = NULL;
	if (!head)
		head = element;
	else
		current->next = element;
	current = element;
	if (GTK_IS_CONTAINER(widget))
	{
		GList *children = gtk_container_get_children(GTK_CONTAINER(widget));
		for (GList *item = children; item != NULL; item = item->next)
		{
			GtkWidget *child = GTK_WIDGET(item->data);
			t_element *child_hierarchy = create_widget_hierarchy(child, element->name);
			if (child_hierarchy)
			{
				child_hierarchy->next = element->children;
				element->children = child_hierarchy;
			}
		}
		g_list_free(children);
	}
	return head;
}

void	save_hierarchy(t_element *head, FILE *file, int depth)
{
	t_element *current = head;
	while (current)
	{
		for (int i = 0; i < depth; i++)
			fprintf(file, "   ");
		fprintf(file, "[ %s ]= dentro =[ %s ]\n", current->name, current->parent);
		save_hierarchy(current->children, file, depth + 1);
		current = current->next;
	}
}

void	free_hierarchy(t_element *head)
{
	if (head == NULL)
		return ;
	free_hierarchy(head->children);
	free_hierarchy(head->next);
	free(head);
}

void	printh(GtkWidget *wg, const char *main_name, const char *files)
{
	t_element *hierarchy;
	FILE *file;

	hierarchy = create_widget_hierarchy(wg, main_name);
	if (!hierarchy)
	{
		printf("Erro ao criar hierarquia\n");
		return;
	}
	file = fopen(files, "w");
	if (!file)
	{
		printf("Erro ao abrir o arquivo %s\n", files);
		free_hierarchy(hierarchy);
		return;
	}
	save_hierarchy(hierarchy, file, 0);
	fclose(file);
	free_hierarchy(hierarchy);
}

