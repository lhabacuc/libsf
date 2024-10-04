#include "libsf_des.h"

void update_position(GtkWidget *widget, int x, int y)
{
    // Atualiza a posição do widget no contêiner GtkFixed
    gtk_fixed_move(GTK_FIXED(gtk_widget_get_parent(widget)), widget, x, y);
}


// Função para aplicar um CSS global a todos os widgets
void apply_global_css(const gchar *css_file_path) {
    GtkCssProvider *css_provider;
    GtkStyleContext *context;
    GtkStyleProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_file(css_provider, g_file_new_for_path(css_file_path), NULL);

    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    provider = GTK_STYLE_PROVIDER(css_provider);
    gtk_style_context_add_provider_for_screen(screen, provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(css_provider);
}

// Função para adicionar uma classe CSS a um widget
void add_css_class(GtkWidget *widget, const gchar *class_name) {
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_class(context, class_name);
}

// Função para remover uma classe CSS de um widget
void remove_css_class(GtkWidget *widget, const gchar *class_name) {
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(widget);
    gtk_style_context_remove_class(context, class_name);
}

// Função para definir uma propriedade CSS dinamicamente em um widget
void set_css_property(GtkWidget *widget, const gchar *property, const gchar *value) {
    GtkCssProvider *css_provider;
    GtkStyleContext *context;
    gchar *css;

    context = gtk_widget_get_style_context(widget);
    css_provider = gtk_css_provider_new();
    
    // Monta a string de CSS para aplicar
    css = g_strdup_printf("%s {%s: %s;}", gtk_widget_get_name(widget), property, value);
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_free(css);
    g_object_unref(css_provider);
}

// Função para aplicar CSS a um widget específico baseado em seu nome
void apply_css_to_named_widget(GtkWidget *widget, const gchar *css_file_path) {
    GtkCssProvider *css_provider;
    GtkStyleContext *context;

    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_file(css_provider, g_file_new_for_path(css_file_path), NULL);

    context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(css_provider);
}

// Função para resetar o estilo de um widget
void reset_widget_style(GtkWidget *widget) {
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(widget);
    gtk_style_context_remove_provider(context, GTK_STYLE_PROVIDER_PRIORITY_USER);
   // gtk_style_context_remove_all_classes(context);
}

// Função para criar e adicionar um botão a um contêiner
GtkWidget* create_and_add_button(GtkBox *box, const gchar *label_text) {
    GtkWidget *button;

    button = gtk_button_new_with_label(label_text);
    gtk_box_pack_start(box, button, TRUE, TRUE, 0);

    return button;
}

void apply_global_csss(GtkWidget *widget, const gchar *css_file_path) {
    GtkCssProvider *css_provider = gtk_css_provider_new();
    GdkDisplay *display;
    GdkScreen *screen;

    // Carregar o CSS a partir do arquivo
    if (!gtk_css_provider_load_from_file(css_provider, g_file_new_for_path(css_file_path), NULL)) {
        g_warning("Failed to load CSS from file: %s", css_file_path);
    }

    // Obter o display e a tela padrão
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    // Adicionar o provedor de estilo ao contexto de estilo da tela
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(css_provider);
}

void apply_css_to_box(GtkBox *box, const gchar *css) {
    GtkCssProvider *css_provider = gtk_css_provider_new();
    GtkStyleContext *context;
    GtkWidget *child;

    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    gtk_container_forall(GTK_CONTAINER(box), (GtkCallback) gtk_widget_get_style_context, css_provider);

    g_object_unref(css_provider);
}

void load_css_from_file(const gchar *filename) {
    GtkCssProvider *css_provider = gtk_css_provider_new();
    GtkStyleContext *context;
    GtkWidget *widget;
    GFile *file = g_file_new_for_path(filename);

    gtk_css_provider_load_from_file(css_provider, file, NULL);
    g_object_unref(file);

    // Aplicar CSS a todos os widgets da aplicação
    context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(css_provider);
}

void set_sombra(GtkWidget *widget, const char *shadow) 
{
    char css[100];
    snprintf(css, sizeof(css), "%s { box-shadow: %s; }", gtk_widget_get_name(widget), shadow);
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    gtk_style_context_add_provider(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(widget)),
                                   GTK_STYLE_PROVIDER(css_provider),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void add_css_to_theme(const gchar *css) {
    GtkCssProvider *css_provider = gtk_css_provider_new();

    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(css_provider);
}

void	apply_css_to_widget(GtkWidget *widget, const gchar *css) {
	GtkCssProvider *css_provider = gtk_css_provider_new();
	GtkStyleContext *context;

	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(widget);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	g_object_unref(css_provider);
}

GtkWidget*	create_styled_button(const gchar *label, const gchar *css)
{
	GtkWidget *button = gtk_button_new_with_label(label);
	apply_css_to_widget(button, css);
	return (button);
}

GtkWidget*	create_styled_progress_bar(void)
{
    GtkWidget *progress_bar = gtk_progress_bar_new();
    const gchar *css = 
        "progress {"
        "   width: 100%;"
        "   height: 20px;"
        "   border-radius: 10px;"
        "   background: #e0e0e0;"
        "}"
        "progress::-webkit-progress-bar {"
        "   background: #e0e0e0;"
        "}"
        "progress::-webkit-progress-value {"
        "   background: #4caf50;"
        "}"
        "progress::-moz-progress-bar {"
        "   background: #4caf50;"
        "}";
    apply_css_to_widget(progress_bar, css);
    return (progress_bar);
}

GtkWidget*	create_button_css(const gchar *label, const gchar *bg_color, const gchar *text_color, const gchar *border_color, const gchar *focus_bg_color, char *s)
{
    GtkWidget *button = gtk_button_new_with_label(label);

    gchar *css = g_strdup_printf(
        "button {"
        "   background: %s;"
        "   color: %s;"
        "   border: 2px solid %s;"
        "   border-radius: 5px;"
        "   padding: 10px 20px;"
        "   font-size: 16px;"
        "    opacity: %s;"
        "   cursor: pointer;"
        "   transition: background 0.3s ease, border-color 0.3s ease;"
        "}"
        "button:hover {"
        "   background: %s;"
        "   border-color: %s;"
        "}", 
        bg_color, text_color, border_color, s, focus_bg_color, border_color
    );

    apply_css_to_widget(button, css);
    g_free(css);
    return button;
}

void	apply_css_tool(GtkWidget *widget, const gchar *css)
{
	GtkCssProvider *css_provider = gtk_css_provider_new();
	GtkStyleContext *context;

	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(widget);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	g_object_unref(css_provider);
}

void apply_css_to_window(GtkWidget *window, GtkCssProvider *css_provider)
{
    GtkStyleContext *context = gtk_widget_get_style_context(window);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void apply_css_window(GtkWidget *widget, const gchar *css)
{
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);

    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_widget_queue_draw(widget);
    g_object_unref(css_provider);
}

GtkCssProvider* create_css_provider(const gchar *css)
{
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    return css_provider;
}

// Função para criar uma GtkListBox
GtkWidget* list_box(void)
{
    GtkWidget *list_box = gtk_list_box_new();
    gtk_widget_set_name(list_box, "list_box"); // Nomear o widget para aplicar CSS
    return list_box;
}

// Função para adicionar um item à GtkListBox
void	add_item_to_list_box(GtkWidget *list_box, const gchar *item_label)
{
	GtkWidget *list_item = gtk_list_box_row_new();
	GtkWidget *label = gtk_label_new(item_label);
	gtk_container_add(GTK_CONTAINER(list_item), label);
	gtk_list_box_insert(GTK_LIST_BOX(list_box), list_item, -1);
}

void	hook_list(GtkWidget *list_box, GCallback callback, gpointer user_data)
{
	g_signal_connect(G_OBJECT(list_box), "row-activated", callback, user_data);
}

GtkWidget* get_row(GtkListBoxRow *row)
{
	return gtk_bin_get_child(GTK_BIN(row));
}

// Função para aplicar CSS a uma GtkListBox
void	apply_list_box_css(GtkWidget *list_box, gchar *css)
{
	GtkCssProvider *css_provider = gtk_css_provider_new();
	GtkStyleContext *context = gtk_widget_get_style_context(list_box);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);
}

// Função personalizada para adicionar widgets a uma GtkBox
void	pack_widget_in_box(GtkWidget *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding)
{
	gtk_box_pack_start(GTK_BOX(box), widget, expand, fill, padding);
}
// Função para adicionar a linha da lista (GtkListBoxRow) à lista (GtkListBox)
void	add_row_to_list(GtkWidget *list_box, GtkWidget *list_box_row)
{
	gtk_container_add(GTK_CONTAINER(list_box), list_box_row);
}

void	add_widget_to_container(GtkWidget *container, GtkWidget *widget)
{
	gtk_container_add(GTK_CONTAINER(container), widget);
}

// Função para criar a área de conteúdo (editor)
GtkWidget* create_content_area()
{
    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll), text_view);

    return scroll;
}

Tool	*img_padrao(int i)
{
    GtkWidget *image;
    const gchar *icon_name;

    switch (i) {
        case 0:
            icon_name = "document-new";         // Criar novo documento
            break;
        case 1:
            icon_name = "document-open";        // Abrir documento
            break;
        case 2:
            icon_name = "document-save";        // Salvar documento
            break;
        case 3:
            icon_name = "document-save-as";     // Salvar como
            break;
        case 4:
            icon_name = "edit-cut";             // Cortar
            break;
        case 5:
            icon_name = "edit-copy";            // Copiar
            break;
        case 6:
            icon_name = "edit-paste";           // Colar
            break;
        case 7:
            icon_name = "edit-undo";            // Desfazer
            break;
        case 8:
            icon_name = "edit-redo";            // Refazer
            break;
        case 9:
            icon_name = "view-refresh";         // Atualizar
            break;
        case 10:
            icon_name = "go-home";              // Página inicial
            break;
        case 11:
            icon_name = "go-next";              // Próximo
            break;
        case 12:
            icon_name = "go-previous";          // Anterior
            break;
        case 13:
            icon_name = "go-up";                // Subir
            break;
        case 14:
            icon_name = "go-down";              // Descer
            break;
        case 15:
            icon_name = "folder";               // Pasta
            break;
        case 16:
            icon_name = "folder-open";          // Abrir pasta
            break;
        case 17:
            icon_name = "user-home";            // Diretório inicial do usuário
            break;
        case 18:
            icon_name = "user-trash";           // Lixeira
            break;
        case 19:
            icon_name = "network-server";       // Servidor de rede
            break;
        case 20:
            icon_name = "media-playback-start"; // Reproduzir
            break;
        case 21:
            icon_name = "media-playback-pause"; // Pausar
            break;
        case 22:
            icon_name = "media-playback-stop";  // Parar
            break;
        case 23:
            icon_name = "media-seek-backward";  // Retroceder
            break;
        case 24:
            icon_name = "media-seek-forward";   // Avançar
            break;
        case 25:
            icon_name = "media-eject";          // Ejetar
            break;
        case 26:
            icon_name = "audio-volume-high";    // Volume alto
            break;
        case 27:
            icon_name = "audio-volume-low";     // Volume baixo
            break;
        case 28:
            icon_name = "audio-volume-muted";   // Mudo
            break;
        case 29:
            icon_name = "dialog-warning";       // Aviso
            break;
        default:
            icon_name = "image-missing";        // Imagem ausente
            break;
    }

    image = gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_DIALOG);
    return image;
}

// Função de callback para eventos de hover
gboolean on_hover_event(GtkWidget *widget, GdkEventCrossing *event, gpointer user_data)
{
	HoverData *data = (HoverData *)user_data;
	Position pos;
	pos.x = (int)event->x;
	pos.y = (int)event->y;
	pos.status = (event->type == GDK_ENTER_NOTIFY) ? 1 : 0;

	if (data->callback)
		data->callback(widget, data->user_data, pos);

	return TRUE;
}

// Função hover_hook que vincula o callback ao evento de hover (entrada e saída)
void	hover_hook(GtkWidget *widget, void (*callback)(GtkWidget*, gpointer, Position), gpointer p)
{
	HoverData *hover_data = g_new(HoverData, 1);
	hover_data->callback = callback;
	hover_data->user_data = p;

	gtk_widget_add_events(widget, GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK);
	g_signal_connect(widget, "enter-notify-event", G_CALLBACK(on_hover_event), hover_data);
	g_signal_connect(widget, "leave-notify-event", G_CALLBACK(on_hover_event), hover_data);
}


const	char* get_theme()
{
	GtkSettings *settings = gtk_settings_get_default();
	gchar *theme_name = NULL;

	g_object_get(settings, "gtk-theme-name", &theme_name, NULL);
	if (theme_name)
		g_free(theme_name);
	else
		return ("null");
	return (theme_name);
}

GdkPixbuf*	redimensionar_imagem(const char *caminho_imagem, int largura, int altura)
{
 	GError *erro = NULL;

	GdkPixbuf *pixbuf_original = gdk_pixbuf_new_from_file(caminho_imagem, &erro);
	if (!pixbuf_original)
	{
		g_printerr("Erro ao carregar imagem: %s\n", erro->message);
		g_error_free(erro);
		return (NULL);
	}
	GdkPixbuf *pixbuf_redimensionada = gdk_pixbuf_scale_simple(pixbuf_original, largura, altura, GDK_INTERP_BILINEAR);
	g_object_unref(pixbuf_original);
	return (pixbuf_redimensionada);
}














