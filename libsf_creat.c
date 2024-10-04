#include "libsf.h"
//# define GdkEventKey EventKey
# define hover "enter-notify-event"
// Function to create a quick icon
Tool	*create_quick_icon(const char *icon_name)
{
	return (gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_BUTTON));
}

// Função para configurar um manipulador de eventos genérico
void sf_hook(GtkWidget *widget, const gchar *event_name,
                       void (*callback)(GtkWidget *, gpointer), gpointer user_data)
{
	g_signal_connect(widget, event_name, G_CALLBACK(callback), user_data);
}

// Function to create a quick text
Tool	*create_quick_text(const char *text)
{
	return (gtk_label_new(text));
}

void	set_size(GtkWidget *widget, int width, int height)
{
	if (GTK_IS_WIDGET(widget))
	{
		gtk_widget_set_size_request(widget, width, height);

		GtkWidget *parent = gtk_widget_get_parent(widget);
		while (parent)
		{
			if (GTK_IS_BOX(parent))
			{
				GtkBox *box = GTK_BOX(parent);
				gtk_widget_set_size_request(widget, width, height);
				gtk_box_set_homogeneous(box, FALSE);
				gtk_box_set_spacing(box, 0);
				gtk_widget_queue_resize(parent);
				break ;
			}
			parent = gtk_widget_get_parent(parent);
		}
	}
	else
		g_warning("set_size: O widget fornecido não é um widget GTK válido.");
}
// Function to create a quick header
Tool	*create_quick_header(const char *label)
{
	return (gtk_label_new(label));
}

// Function to create a quick footer
Tool	*create_quick_footer(const char *label)
{
	return (gtk_label_new(label));
}

// Function to create a quick section
Tool	*create_quick_section(const char *label)
{
	return (gtk_label_new(label));
}

// Function to create a quick header text
Tool	*create_quick_header_text(const char *text)
{
	return (gtk_label_new(text));
}

// Function to create a quick footer text
Tool	*create_quick_footer_text(const char *text)
{
	return (gtk_label_new(text));
}

// Function to create a quick section text
Tool	*create_quick_section_text(const char *text)
{
	return (gtk_label_new(text));
}

// Function to create a quick label
Tool	*create_quick_label(const char *text)
{
	return (gtk_label_new(text));
}

// Function to create a quick icon button
Tool	*create_quick_icon_button(const char *icon_name, GCallback callback, gpointer data)
{
	Tool *button = gtk_button_new();
	Tool *icon = create_quick_icon(icon_name);
	gtk_button_set_image(GTK_BUTTON(button), icon);
	g_signal_connect(button, "clicked", callback, data);
	return (button);
}

// Function to create a quick icon label
Tool	*create_quick_icon_label(const char *icon_name, const char *text)
{
	Tool *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Tool *icon = create_quick_icon(icon_name);
	Tool *label = create_quick_label(text);
	gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
	return (box);
}

// Function to create a quick icon footer
Tool	*create_quick_icon_footer(const char *icon_name, const char *text)
{
	Tool *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Tool *icon = create_quick_icon(icon_name);
	Tool *label = create_quick_footer(text);
	gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
	return (box);
}

// Function to create a quick icon section
Tool	*create_quick_icon_section(const char *icon_name, const char *text)
{
	Tool *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Tool *icon = create_quick_icon(icon_name);
	Tool *label = create_quick_section(text);
	gtk_box_pack_start(GTK_BOX(box), icon, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
	return (box);
}

// Função para criar um objeto
Objeto *criar_objeto(Tool *widget, int x, int y, int largura, int altura, gboolean visivel,
                     void (*desenho_callback)(Tool *, cairo_t *, gpointer), gpointer dados)
{
    Objeto *objeto;

    objeto = g_malloc(sizeof(Objeto));
    objeto->widget = widget;
    objeto->x = x;
    objeto->y = y;
    objeto->largura = largura;
    objeto->altura = altura;
    objeto->visivel = visivel;
    objeto->desenho_callback = desenho_callback;
    objeto->dados = dados;

    // Configura o tamanho e a visibilidade do widget
    gtk_widget_set_size_request(widget, largura, altura);
    gtk_widget_set_visible(widget, visivel);

    // Adiciona o widget à janela principal (ou container)
    add_to_fixed(GTK_FIXED(gtk_widget_get_parent(widget)), widget, x, y);

    // Conecta o sinal de desenho ao callback, se fornecido
    if (desenho_callback)
        g_signal_connect(widget, "draw", F(desenho_callback), dados);

    return objeto;
}

// Função para definir a visibilidade do objeto
void definir_visibilidade(Objeto *objeto, gboolean visivel)
{
    if (objeto)
    {
        gtk_widget_set_visible(objeto->widget, visivel);
        objeto->visivel = visivel;
    }
}

// Função para mover o objeto para uma nova posição
void mover_objeto(Objeto *objeto, int novo_x, int novo_y)
{
    if (objeto)
    {
        add_to_fixed(GTK_FIXED(gtk_widget_get_parent(objeto->widget)), objeto->widget, novo_x, novo_y);
        objeto->x = novo_x;
        objeto->y = novo_y;
    }
}

// Função para redimensionar o objeto
void redimensionar_objeto(Objeto *objeto, int nova_largura, int nova_altura)
{
    if (objeto)
    {
        gtk_widget_set_size_request(objeto->widget, nova_largura, nova_altura);
        objeto->largura = nova_largura;
        objeto->altura = nova_altura;
        gtk_widget_queue_draw(objeto->widget);
    }
}

// Função para desenhar o objeto (chama a função de callback se definida)
void desenhar_objeto(Objeto *objeto, cairo_t *cr)
{
    if (objeto && objeto->desenho_callback)
        objeto->desenho_callback(objeto->widget, cr, objeto->dados);
}

static gboolean on_key_event(Tool *widget, GdkEventKey *event, gpointer data)
{
    t_key_event_data *key_data = (t_key_event_data *)data;
    if (key_data->key_handler)
        key_data->key_handler(event, key_data->user_data);
    return FALSE;
}

// Função para adicionar um manipulador de eventos de tecla
void	hook_key(Tool *widget, void (*key_handler)(GdkEventKey *event, gpointer user_data), gpointer user_data)
{
    if (GTK_IS_WIDGET(widget))
    {
        t_key_event_data *key_data = g_malloc(sizeof(t_key_event_data));
        key_data->key_handler = key_handler;
        key_data->user_data = user_data;

        g_signal_connect(widget, KEY_PRESS_EVENT, G_CALLBACK(on_key_event), key_data);
    }
}



// Função para colocar um pixel em uma área de desenho
void pixel_put(Tool *drawing_area, int x, int y, double red, double green, double blue)
{
    cairo_surface_t *surface = gtk_widget_get_window(drawing_area);
    cairo_t *cr = gdk_cairo_create(surface);

    cairo_set_source_rgb(cr, red, green, blue);

    cairo_rectangle(cr, x, y, 1, 1);
    cairo_fill(cr);

    cairo_destroy(cr);
}

// Função para alterar a cor de fundo de um widget
void set_background_color(Tool *widget, const gchar *color)
{
    if (GTK_IS_WIDGET(widget) && color != NULL)
    {
        GtkCssProvider *provider = gtk_css_provider_new();
        gchar *css = g_strdup_printf("widget { background-color: %s; }", color);

        gtk_css_provider_load_from_data(provider, css, -1, NULL);

        GtkStyleContext *context = gtk_widget_get_style_context(widget);
        gtk_style_context_add_provider(context,
                                       GTK_STYLE_PROVIDER(provider),
                                       GTK_STYLE_PROVIDER_PRIORITY_USER);

        g_free(css);
        g_object_unref(provider);
    }
}


// Função para ocultar um widget
void hide_widget(Tool *widget)
{
    if (GTK_IS_WIDGET(widget))
    {
        gtk_widget_hide(widget);
    }
}

// Função para exibir um widget
void show_widget(Tool *widget)
{
    if (GTK_IS_WIDGET(widget))
    {
        gtk_widget_show(widget);
    }
}

// Função genérica para conectar um callback a um evento de um widget
void hook(Tool *widget, int event, GCallback callback, gpointer user_data)
{
	const char *event_name = if_event(event);
	if (event_name)
		g_signal_connect(widget, event_name, callback, user_data);
}

static void initialize_app(gpointer user_data)
{
	Tool *window = GTK_WIDGET(user_data);
	g_print("Aplicativo inicializado com a janela: %p\n", window);
}


// init win all
void	init_windows(t_window_manager *wm)
{
	wm->main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->main_window), "Main");

	wm->settings_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->settings_window), "Settings");

	wm->content_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->content_window), "Content Viewer");

	wm->dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->dialog_window), "Dialog");

	wm->tools_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->tools_window), "Tools");

	wm->help_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->help_window), "Help");

	wm->temp_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->temp_window), "Temporary");

	wm->fixed_layout_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->fixed_layout_window), "Fixed Layout");

	wm->grid_layout_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->grid_layout_window), "Grid Layout");

	wm->data_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->data_window), "Data");

	wm->preview_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(wm->preview_window), "Preview");
}

Appl	*appl_new(const char *app_id)
{
	Appl *app;

	app = gtk_application_new(app_id, G_APPLICATION_REPLACE);
	if (app == NULL)
	{
		// erros apll aqui
		return (NULL);
	}
	return (app);
}

void	appl_activate(Appl *app, GCallback activate_callback, Pont user_data)
{
	if (app != NULL)
		g_signal_connect(app, "activate", G_CALLBACK(activate_callback), user_data);
}

int	appl_run(Appl *app, int argc, char **argv)
{
	int status;

	if (app != NULL)
	{
		status = g_application_run(G_APPLICATION(app), argc, argv);
		g_object_unref(app);
		return (status);
	}
	return (-1);
}
