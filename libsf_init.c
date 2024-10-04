#include "libsf.h"

/**
 * Define a cor de fundo da janela.
 * @param window A janela na qual a cor de fundo deve ser definida.
 * @param color_hex O valor hexadecimal da cor de fundo (por exemplo, 0xRRGGBB).
 */

void	window_position(Tool *window, int x, int y)
{
	gtk_window_move((GtkWindow*)window, x, y);
}
void	window_center(Tool *window, int window_width, int window_height)
{
	gint screen_height;
	gint screen_width;
	// Obtém a tela do display
	GdkScreen *screen = gdk_screen_get_default();
	// Obtém a largura e altura da tela
	screen_width = (gint)gdk_screen_get_width(screen);
	screen_height = (gint)gdk_screen_get_height(screen);
	// Calcula a posição para centralizar a janela
	gint x = (screen_width - window_width) / 2;
	gint y = (screen_height - window_height) / 2;
	// Move a janela para a posição calculada
	window_position(window, x, y);
}

void	set_window_background(Tool *window, guint color_hex)
{
	if (!GTK_IS_WINDOW(window))
	{
		fprintf(stderr, "O widget fornecido não é uma janela.\n");
		return;
	}
	GtkCssProvider *provider = gtk_css_provider_new();
	gchar css[128];
	g_snprintf(css, sizeof(css),
               "window { "
               "background-color: #%06x; "
               "}", 
               color_hex);

	gtk_css_provider_load_from_data(provider, css, -1, NULL);
	GtkStyleContext *context = gtk_widget_get_style_context(window);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	g_object_unref(provider);
}

void	event_hook(GtkWidget *widget, int event, SignalCallback callback, Pont data)
{
	const char *signal_name = if_event(event);
	g_signal_connect(widget, signal_name, G_CALLBACK(callback), data);
}

char	*get_uni_name(char *nome)
{
	static int	counter = 0;
	char		*name0;
	int			size;

	size = snprintf(NULL, 0, "%s%d", nome, counter) + 1;
	name0 = (char *)malloc(size * sizeof(char));
	if (!name0)
		return (NULL);
	snprintf(name0, size, "%s%d", nome, counter);
	counter++;
	return (name0);
}

void	init_butoon(Butoon *btl)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];

	if (!btl || !btl->fixed)
	{
		fprintf(stderr, "Botão ou contêiner inválido.\n");
		return ;
	}
	if (!btl->Ob)
	{
		btl->Ob = gtk_button_new_with_label(btl->texto ? btl->texto : "Botão");
		gtk_fixed_put(GTK_FIXED(btl->fixed), btl->Ob, btl->x, btl->y);
	}
	else
		gtk_button_set_label(GTK_BUTTON(btl->Ob), btl->texto ? btl->texto : "Botão");
	gtk_widget_set_size_request(btl->Ob, btl->largura > 0 ? btl->largura : 100,
		btl->altura > 0 ? btl->altura : 30);
	gtk_widget_set_name(btl->Ob, "butoon");

	css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#butoon { background-color: #%06x; color: #%06x; border: %dpx solid #%06x; }",
		btl->cor, btl->textcor, btl->bord, btl->bcor);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(btl->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);
	
	if (btl->func)
	{
		const char *signal_name = if_event(btl->event);
		if (btl->event)
			g_signal_connect(G_OBJECT(btl->Ob), signal_name,
			G_CALLBACK(btl->func), btl->dados_adicionais);
	}
	
	if (btl->visivel == VISIVEL)
		gtk_widget_show(btl->Ob);
	else if (btl->visivel == INVISIVEL)
		gtk_widget_hide(btl->Ob);
	else
	{
		gtk_widget_destroy(btl->Ob);
		btl->Ob = NULL;
	}
}

void init_imagem(Imagem *img)
{
    if (!img || !img->fixed)
    {
        fprintf(stderr, "Imagem ou contêiner inválido.\n");
        return ;
    }
 
    if (!img->Ob)
    {
        img->Ob = gtk_image_new_from_file(img->file_path ? img->file_path : "");
        gtk_fixed_put(GTK_FIXED(img->fixed), img->Ob, img->x, img->y);
      //  printf("Imagem criada e posicionada em (%d, %d).\n", img->x, img->y);
    }
    else
    {
        gtk_image_set_from_file(GTK_IMAGE(img->Ob), img->file_path ? img->file_path : "");
        gtk_widget_set_size_request(img->Ob, img->largura > 0 ? img->largura : 100,
            img->altura > 0 ? img->altura : 100);
        gtk_fixed_move(GTK_FIXED(img->fixed), img->Ob, img->x, img->y);
       // printf("Imagem atualizada e reposicionada em (%d, %d).\n", img->x, img->y);
    }

    gtk_widget_set_name(img->Ob, "imagem");

    GtkCssProvider *css_provider = gtk_css_provider_new();
    char css[256];
    snprintf(css, sizeof(css),
        "#imagem { background-color: #%06x; border: %dpx solid #%06x; }",
        img->cor, img->bord, img->bcor);
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(img->Ob);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(css_provider);

    if (img->visivel == VISIVEL)
        gtk_widget_show(img->Ob);
    else if (img->visivel == INVISIVEL)
        gtk_widget_hide(img->Ob);
    else
    {
        gtk_widget_destroy(img->Ob);
        img->Ob = NULL;
    }
}



void init_label(Label *lbl)
{
    GtkCssProvider *css_provider;
    GtkStyleContext *context;
    char css[256];

    if (!lbl || !lbl->fixed)
    {
        fprintf(stderr, "Label ou contêiner inválido.\n");
        return;
    }
    if (!lbl->Ob)
    {
        lbl->Ob = gtk_label_new(lbl->texto ? lbl->texto : "Label");
        gtk_fixed_put(GTK_FIXED(lbl->fixed), lbl->Ob, lbl->x, lbl->y);
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(lbl->Ob), lbl->texto ? lbl->texto : "Label");
    }
    gtk_widget_set_size_request(lbl->Ob, lbl->largura > 0 ? lbl->largura : 100,
                                lbl->altura > 0 ? lbl->altura : 30);
    gtk_widget_set_name(lbl->Ob, "label"); // Defina um nome único

    // Criação do provider CSS e definição do estilo
    css_provider = gtk_css_provider_new();
    snprintf(css, sizeof(css),
        "#label { color: #%06x; border: %dpx solid #%06x; background-color: #%06x; }",
        lbl->textcor, lbl->bord, lbl->bcor, lbl->cor);
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    context = gtk_widget_get_style_context(lbl->Ob);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
                                    GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(css_provider);

    if (lbl->visivel == VISIVEL)
        gtk_widget_show(lbl->Ob);
    else if (lbl->visivel == INVISIVEL)
        gtk_widget_hide(lbl->Ob);
    else
    {
        gtk_widget_destroy(lbl->Ob);
        lbl->Ob = NULL;
    }
}



void init_drawing_area(DrawingArea *da)
{
    GtkCssProvider    *css_provider;
    GtkStyleContext   *context;
    char              css[256];

    if (!da || !da->fixed)
    {
        fprintf(stderr, "DrawingArea ou contêiner inválido.\n");
        return ;
    }
    if (!da->Ob)
    {
        da->Ob = gtk_drawing_area_new();
        gtk_fixed_put(GTK_FIXED(da->fixed), da->Ob, da->x, da->y);
    }

    gtk_widget_set_size_request(da->Ob, da->largura > 0 ? da->largura : 100,
        da->altura > 0 ? da->altura : 100);
    gtk_widget_set_name(da->Ob, "drawing_area");

    css_provider = gtk_css_provider_new();
    snprintf(css, sizeof(css),
        "#drawing_area { background-color: #%06x; border: %dpx solid #%06x; }",
        da->cor, da->bord, da->bcor);
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    context = gtk_widget_get_style_context(da->Ob);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(css_provider);

    if (da->draw_callback)
        g_signal_connect(G_OBJECT(da->Ob), "draw", G_CALLBACK(da->draw_callback), da->data);

    if (da->visivel == VISIVEL)
        gtk_widget_show(da->Ob);
    else if (da->visivel == INVISIVEL)
        gtk_widget_hide(da->Ob);
    else
    {
        gtk_widget_destroy(da->Ob);
        da->Ob = NULL;
    }
}


void	init_file_chooser(FileChooser *fc)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];

	if (!fc || !fc->fixed)
	{
		fprintf(stderr, "FileChooser ou contêiner inválido.\n");
		return ;
	}
	if (!fc->Ob)
	{
		fc->Ob = gtk_file_chooser_button_new(fc->title ? fc->title : "Escolha um arquivo", fc->action);
		gtk_fixed_put(GTK_FIXED(fc->fixed), fc->Ob, fc->x, fc->y);
	}
	gtk_widget_set_size_request(fc->Ob, fc->largura > 0 ? fc->largura : 200,
		fc->altura > 0 ? fc->altura : 30);

	gtk_widget_set_name(fc->Ob, "filechooser");

	css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#filechooser { background-color: #%06x; border: %dpx solid #%06x; }",
		fc->cor, fc->bord, fc->bcor);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(fc->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);

	if (fc->file_activated_callback)
		g_signal_connect(G_OBJECT(fc->Ob), "file-activated", G_CALLBACK(fc->file_activated_callback), fc->data);

	if (fc->visivel == VISIVEL)
		gtk_widget_show(fc->Ob);
	else if (fc->visivel == INVISIVEL)
		gtk_widget_hide(fc->Ob);
	else
	{
		gtk_widget_destroy(fc->Ob);
		fc->Ob = NULL;
	}
}



void	init_context_menu(ContextMenu *cm)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];
	Tool		*item;

	if (!cm || !cm->fixed)
	{
		fprintf(stderr, "ContextMenu ou contêiner inválido.\n");
		return ;
	}
	if (!cm->Ob)
	{
		cm->Ob = gtk_menu_new();
		gtk_fixed_put(GTK_FIXED(cm->fixed), cm->Ob, cm->x, cm->y);

		for (int i = 0; i < cm->item_count; ++i)
		{
			item = gtk_menu_item_new_with_label(cm->items[i]);
			gtk_menu_shell_append(GTK_MENU_SHELL(cm->Ob), item);
			if (cm->item_callbacks[i])
				g_signal_connect(item, "activate", G_CALLBACK(cm->item_callbacks[i]), cm->item_data[i]);
		}
		gtk_widget_show_all(cm->Ob);
	}
	else
		gtk_widget_set_size_request(cm->Ob, cm->largura > 0 ? cm->largura : 200,
			cm->altura > 0 ? cm->altura : 200);

	cm->css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#context_menu { background-color: #%06x; }"
		"#context_menu > * { color: #%06x; border: %dpx solid #%06x; }",
		cm->cor, cm->textcor, cm->bord, cm->bcor);
	gtk_css_provider_load_from_data(cm->css_provider, css, -1, NULL);

	context = gtk_widget_get_style_context(cm->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(cm->css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);

	for (int i = 0; i < cm->item_count; ++i)
	{
		item = g_list_nth_data(gtk_container_get_children(GTK_CONTAINER(cm->Ob)), i);
		gtk_widget_set_name(item, "menu_item");
		context = gtk_widget_get_style_context(item);
		gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(cm->css_provider),
			GTK_STYLE_PROVIDER_PRIORITY_USER);
	}

	g_object_unref(cm->css_provider);

	if (cm->visivel == 1)
		gtk_widget_show(cm->Ob);
	else if (cm->visivel == 0)
		gtk_widget_hide(cm->Ob);
	else
	{
		gtk_widget_destroy(cm->Ob);
		cm->Ob = NULL;
	}
}

void	init_progress_bar(ProgressBar *pb)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];

	if (!pb || !pb->fixed)
	{
		fprintf(stderr, "ProgressBar ou contêiner inválido.\n");
		return ;
	}
	if (!pb->Ob)
	{
		pb->Ob = gtk_progress_bar_new();
		gtk_fixed_put(GTK_FIXED(pb->fixed), pb->Ob, pb->x, pb->y);
	}
	gtk_widget_set_size_request(pb->Ob, pb->largura > 0 ? pb->largura : 200,
		pb->altura > 0 ? pb->altura : 30);

	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pb->Ob), pb->valor);

	gtk_widget_set_name(pb->Ob, "progressbar");

	css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#progressbar { background-color: #%06x; border: %dpx solid #%06x; }",
		pb->cor, pb->bord, pb->bcor);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(pb->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);

	if (pb->update_callback)
		g_signal_connect(G_OBJECT(pb->Ob), "value-changed", G_CALLBACK(pb->update_callback),
			pb->update_callback_data);

	if (pb->visivel == VISIVEL)
		gtk_widget_show(pb->Ob);
	else if (pb->visivel == INVISIVEL)
		gtk_widget_hide(pb->Ob);
	else
	{
		gtk_widget_destroy(pb->Ob);
		pb->Ob = NULL;
	}
}


void	init_radio_button(RadioButton *rb)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];

	if (!rb || !rb->fixed)
	{
		fprintf(stderr, "RadioButton ou contêiner inválido.\n");
		return ;
	}
	if (!rb->Ob)
	{
		rb->Ob = gtk_radio_button_new_with_label(NULL, rb->label ? rb->label : "Opção");
		gtk_fixed_put(GTK_FIXED(rb->fixed), rb->Ob, rb->x, rb->y);
	}
	else
		gtk_radio_button_set_group(GTK_RADIO_BUTTON(rb->Ob), rb->label ? rb->label : "Opção");
	gtk_widget_set_size_request(rb->Ob, rb->largura > 0 ? rb->largura : 200,
		rb->altura > 0 ? rb->altura : 30);
	gtk_widget_set_name(rb->Ob, "radio_button");

	css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#radio_button { color: #%06x; border: %dpx solid #%06x; }",
		rb->textcor, rb->bord, rb->bcor);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(rb->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);

	if (rb->toggled_callback)
		g_signal_connect(G_OBJECT(rb->Ob), "toggled", G_CALLBACK(rb->toggled_callback),
			rb->data);
	if (rb->visivel == VISIVEL)
		gtk_widget_show(rb->Ob);
	else if (rb->visivel == INVISIVEL)
		gtk_widget_hide(rb->Ob);
	else
	{
		gtk_widget_destroy(rb->Ob);
		rb->Ob = NULL;
	}
}

void	init_status_bar(StatusBar *sb)
{
    GtkCssProvider    *css_provider;
    GtkStyleContext   *context;
    char              css[256];

    if (!sb || !sb->fixed)
    {
        fprintf(stderr, "StatusBar ou contêiner inválido.\n");
        return ;
    }

    if (!sb->Ob)
    {
        sb->Ob = gtk_statusbar_new();
        gtk_fixed_put(GTK_FIXED(sb->fixed), sb->Ob, sb->x, sb->y);
    }

    gtk_widget_set_size_request(sb->Ob, sb->largura > 0 ? sb->largura : 200,
        sb->altura > 0 ? sb->altura : 30);

    if (sb->message)
        gtk_statusbar_push(GTK_STATUSBAR(sb->Ob), 0, sb->message);

    gtk_widget_set_name(sb->Ob, "statusbar");

    // Aplicar o CSS
    css_provider = gtk_css_provider_new();
    snprintf(css, sizeof(css),
        "#statusbar { background-color: #%06x; color: #%06x; border: %dpx solid #%06x; }",
        sb->cor, sb->textcor, sb->bord, sb->bcor);
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    context = gtk_widget_get_style_context(sb->Ob);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(css_provider);

    if (sb->visivel == VISIVEL)
        gtk_widget_show(sb->Ob);
    else if (sb->visivel == INVISIVEL)
        gtk_widget_hide(sb->Ob);
    else
    {
        gtk_widget_destroy(sb->Ob);
        sb->Ob = NULL;
    }
}


void	init_slider(Slider *sl)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];

	if (!sl || !sl->fixed)
	{
		fprintf(stderr, "Slider ou contêiner inválido.\n");
		return ;
	}
	if (!sl->Ob)
	{
		sl->Ob = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, sl->min_value, sl->max_value, 1);
		gtk_fixed_put(GTK_FIXED(sl->fixed), sl->Ob, sl->x, sl->y);
	}
	else
		gtk_range_set_range(GTK_RANGE(sl->Ob), sl->min_value, sl->max_value);
	gtk_range_set_value(GTK_RANGE(sl->Ob), sl->value);
	gtk_widget_set_size_request(sl->Ob, sl->largura > 0 ? sl->largura : 200,
		sl->altura > 0 ? sl->altura : 30);
	gtk_widget_set_name(sl->Ob, "slider"); // Defina um nome único

	css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#slider { background-color: #%06x; }", // Exemplo de estilo; ajuste conforme necessário
		sl->cor);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(sl->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);

	if (sl->value_changed_callback)
		g_signal_connect(G_OBJECT(sl->Ob), "value-changed", G_CALLBACK(sl->value_changed_callback),
			sl->data);

	if (sl->visivel == VISIVEL)
		gtk_widget_show(sl->Ob);
	else if (sl->visivel == INVISIVEL)
		gtk_widget_hide(sl->Ob);
	else
	{
		gtk_widget_destroy(sl->Ob);
		sl->Ob = NULL;
	}
}

void	init_separator(Separator *sep)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];
	GdkRGBA		 color;
	unsigned int	 rgb_color;

	if (!sep || !sep->fixed)
	{
		fprintf(stderr, "Separator ou contêiner inválido.\n");
		return ;
	}
	if (!sep->Ob)
	{
		sep->Ob = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
		gtk_fixed_put(GTK_FIXED(sep->fixed), sep->Ob, sep->x, sep->y);
	}
	gtk_widget_set_size_request(sep->Ob, sep->largura > 0 ? sep->largura : 100,
		sep->altura > 0 ? sep->altura : 10);
	gtk_widget_set_name(sep->Ob, "separator"); // Defina um nome único

	css_provider = gtk_css_provider_new();
	if (sep->cor)
	{
		rgb_color = ((unsigned int)(color.red * 255) << 16) |
			((unsigned int)(color.green * 255) << 8) |
			((unsigned int)(color.blue * 255));

		snprintf(css, sizeof(css),
			"#separator { background-color: #%06x; }",
			rgb_color);
	}
	else
	{
		snprintf(css, sizeof(css),
			"#separator { background-color: #CCCCCC; }"); // Cor padrão se nenhuma cor fornecida
	}
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(sep->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);

	if (sep->visivel == VISIVEL)
		gtk_widget_show(sep->Ob);
	else if (sep->visivel == INVISIVEL)
		gtk_widget_hide(sep->Ob);
	else
	{
		gtk_widget_destroy(sep->Ob);
		sep->Ob = NULL;
	}
}


void	init_EText(Edtext *ent)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];

	if (!ent || !ent->fixed)
	{
		fprintf(stderr, "Entry ou contêiner inválido.\n");
		return ;
	}
	if (!ent->Ob)
	{
		ent->Ob = gtk_entry_new();
		gtk_fixed_put(GTK_FIXED(ent->fixed), ent->Ob, ent->x, ent->y);
	}
	gtk_widget_set_size_request(ent->Ob, ent->largura > 0 ? ent->largura : 100,
		ent->altura > 0 ? ent->altura : 30);

	if (ent->texto)
		gtk_entry_set_text(GTK_ENTRY(ent->Ob), ent->texto);

	gtk_widget_set_name(ent->Ob, "entry"); // Defina um nome único

	css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#entry { background-color: #%06x; color: #%06x; border: %dpx solid #%06x; }",
		ent->cor, ent->textcor, ent->bord, ent->bcor);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
	context = gtk_widget_get_style_context(ent->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);

	if (ent->func)
	{
		const char *signal_name = if_event(ent->event);
		if (ent->event)
			g_signal_connect(G_OBJECT(ent->Ob), signal_name,
			G_CALLBACK(ent->func), ent->dados_adicionais);
	}

	if (ent->visivel == VISIVEL)
		gtk_widget_show(ent->Ob);
	else if (ent->visivel == INVISIVEL)
		gtk_widget_hide(ent->Ob);
	else
	{
		gtk_widget_destroy(ent->Ob);
		ent->Ob = NULL;
	}
}

void init_text_view(TextView *tv)
{
    GtkCssProvider *css_provider;
    GtkStyleContext *context;
    char css[256];

    if (!tv || !tv->fixed)
    {
        fprintf(stderr, "TextView ou contêiner inválido.\n");
        return;
    }

    if (!tv->Ob)
    {
        tv->Ob = gtk_text_view_new();
        gtk_fixed_put(GTK_FIXED(tv->fixed), tv->Ob, tv->x, tv->y);
    }

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv->Ob));

	if (tv->texto)
		gtk_text_buffer_set_text(buffer, tv->texto, -1);

    gtk_widget_set_size_request(tv->Ob, tv->largura > 0 ? tv->largura : 200, tv->altura > 0 ? tv->altura : 100);

    gtk_widget_set_name(tv->Ob, "text_view");

    css_provider = gtk_css_provider_new();
    snprintf(css, sizeof(css), "#text_view { background-color: #%06x; color: #%06x; border: %dpx solid #%06x; }",
             tv->cor, tv->textcor, tv->bord, tv->bcor);
    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);

    context = gtk_widget_get_style_context(tv->Ob);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(css_provider);

    if (tv->func) {
        g_signal_connect(G_OBJECT(buffer), "changed", G_CALLBACK(tv->func), tv->dados_adicionais);
    }

    if (tv->visivel == VISIVEL) {
        gtk_widget_show(tv->Ob);
    } else if (tv->visivel == INVISIVEL) {
        gtk_widget_hide(tv->Ob);
    } else {
        gtk_widget_destroy(tv->Ob);
        tv->Ob = NULL;
    }

    if (!tv->resizable) {
        gtk_widget_set_size_request(tv->Ob, tv->largura, tv->altura);
    }
}


static void apply_css_from_linear_view(LinearView *lv)
{
    GtkCssProvider *css_provider = gtk_css_provider_new();
    char css[512];

    snprintf(css, sizeof(css),
             "#linear-view { background-color: #%s; }"
             "#linear-view row { border: %dpx solid #%s; color: #%s; }",
             lv->background_color ? lv->background_color : "FFFFFF", 
             lv->border_width, 
             lv->border_color ? lv->border_color : "000000",
             lv->item_color ? lv->item_color : "000000");

    gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(css_provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(css_provider);
}



static void apply_css_from_linear_view(LinearView *lv);

void on_item(GtkListBox *listbox, GtkListBoxRow *row, gpointer user_data)
{
	LinearView *lv = (LinearView *)user_data;

	GtkWidget *box = gtk_bin_get_child(GTK_BIN(row));

	if (!GTK_IS_BOX(box))
	{
		g_print("O widget não é um GtkBox.\n");
		return ;
	}

	GList *children = gtk_container_get_children(GTK_CONTAINER(box));

	for (GList *iter = children; iter != NULL; iter = iter->next)
	{
		GtkWidget *child = GTK_WIDGET(iter->data);

		if (GTK_IS_LABEL(child))
		{
			const gchar *label_text = gtk_label_get_text(GTK_LABEL(child));

			if (lv->item_clicked_callback)
				lv->item_clicked_callback(listbox, row, lv->callback_data);
			break ;
		}
	}
	g_list_free(children);
}
// Inicializar LinearView
void	init_linear_view(LinearView *lv)
{
	if (!lv || !lv->fixed)
	{
		fprintf(stderr, "LinearView ou contêiner inválido.\n");
		return;
	}

	if (!lv->listbox)
	{
		lv->listbox = gtk_list_box_new();
		gtk_fixed_put(GTK_FIXED(lv->fixed), lv->listbox, lv->x, lv->y);
	}

	gtk_widget_set_size_request(lv->listbox, lv->largura > 0 ? lv->largura : 200, lv->altura > 0 ? lv->altura : 300);
	gtk_widget_set_name(lv->listbox, "linear-view");

	if (lv->background_color || lv->border_color)
	{
		GtkCssProvider *css_provider = gtk_css_provider_new();
		char css[512] = {0};

		if (lv->background_color)
		{
			snprintf(css, sizeof(css),
				"#linear-view { background-color: #%s; }", lv->background_color);
		}

		if (lv->border_color)
		{
			snprintf(css + strlen(css), sizeof(css) - strlen(css),
				"#linear-view * { border: %dpx solid #%s; }", lv->border_width, lv->border_color);
		}

		gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
		GtkStyleContext *context = gtk_widget_get_style_context(lv->listbox);
		gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		g_object_unref(css_provider);
	}

	for (int i = 0; i < lv->item_count; ++i)
	{
		GtkWidget *row = gtk_box_new(lv->vertical ? GTK_ORIENTATION_VERTICAL : GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *label = gtk_label_new(lv->items[i]);

		gtk_widget_set_name(label, "list-item");

		if (lv->item_color || lv->border_color)
		{
			GtkCssProvider *css_provider = gtk_css_provider_new();
			char css[256];
				snprintf(css, sizeof(css),
					"#list-item { color: #%s; border: %dpx solid #%s; }",
			lv->item_color, lv->border_width, lv->border_color);
			gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
			GtkStyleContext *context = gtk_widget_get_style_context(label);
			gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			g_object_unref(css_provider);
		}

		gtk_box_pack_start(GTK_BOX(row), label, TRUE, TRUE, 0);
		gtk_list_box_insert(GTK_LIST_BOX(lv->listbox), row, -1);
	}

	if (lv->vertical)
		gtk_widget_set_size_request(lv->listbox, lv->largura > 0 ? lv->largura : 200, lv->item_height > 0 ? lv->item_height * lv->item_count : 300);
	else
		gtk_widget_set_size_request(lv->listbox, lv->item_width > 0 ? lv->item_width * lv->item_count : 300, lv->altura > 0 ? lv->altura : 200);

	if (lv->item_clicked_callback)
		g_signal_connect(lv->listbox, "row-activated", G_CALLBACK(on_item), lv);

	if (lv->visivel == 1)
		gtk_widget_show(lv->listbox);
	else
		gtk_widget_hide(lv->listbox);
}


void	force_css(GtkWidget *widget)
{
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider,
        "#map-image { background-color: #f0f0f0; }"
        "#button { background-color: #ff0000; color: #ffffff; }",
        -1, NULL);

    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(css_provider);
}

void	center_img(GtkFixed *fixed, const char *image, int window_w, int window_h, int r)
{
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(image, NULL);
	if (!pixbuf)
	{
		g_printerr("Erro ao carregar a imagem: %s\n", image);
		return;
	}
	int image_width = gdk_pixbuf_get_width(pixbuf);
	int image_height = gdk_pixbuf_get_height(pixbuf);
	double scale_x = (double)window_w / image_width;
	double scale_y = (double)window_h / image_height;
	double scale = fmin(scale_x, scale_y);
	int new_width = image_width * scale - r;
	int new_height = image_height * scale - r;

	GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf,
	new_width, new_height, GDK_INTERP_BILINEAR);
	g_object_unref(pixbuf);
	GtkWidget *imagei = gtk_image_new_from_pixbuf(scaled_pixbuf);
	g_object_unref(scaled_pixbuf);
	int x = (window_w - new_width) / 2;
	int y = (window_h - new_height) / 2;
	gtk_fixed_put(fixed, imagei, x, y);
	gtk_widget_show(imagei);
}

static gboolean	sf_draw_grid(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	GtkAllocation allocation;
	gtk_widget_get_allocation(widget, &allocation);
	int width = allocation.width;
	int height = allocation.height;

	// Define o espaçamento entre os pontos da grade
	int grid_spacing = 50;

	// Define a cor da grade (cinza claro)
	cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);

	// Desenha a grade
	for (int x = 0; x < width; x += grid_spacing)
	{
		for (int y = 0; y < height; y += grid_spacing)
		{
			// Desenha o ponto
			cairo_arc(cr, x, y, 2, 0, 2 * G_PI);
			cairo_fill(cr);

			// Define a cor do texto (preto)
			cairo_set_source_rgb(cr, 0.1, 0.1, 0.1);

			// Cria o texto da coordenada
			char coords[20];
			snprintf(coords, sizeof(coords), "(%d, %d)", x, y);

			// Desenha o texto ao lado do ponto
			cairo_move_to(cr, x + 5, y - 5);
			cairo_show_text(cr, coords);

			// Retorna para a cor da grade para o próximo ponto
			cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
		}
	}

	return FALSE;
}

void	criar_grade_locali(GtkFixed *fixed, int larg, int altur)
{
	GtkWidget *drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(drawing_area, larg, altur);
	gtk_fixed_put(GTK_FIXED(fixed), drawing_area, 0, 0);
	g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(sf_draw_grid), NULL);
}
