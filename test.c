/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:06:48 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/02 17:06:51 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libsf.h"

void test_callback(Sbox *listbox, BoxRow *row, gpointer user_data)
{
	const gchar *label_text = NULL;
	BIN_LISTVIEW(row, label_text);

	if (label_text != NULL)
		sf_printf("Item clicado: %s\n", label_text);
}

int	main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	Tool *window =create_window_s("Exemplo de LinearView", 400, 300);

	Tool *fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	gchar *items[] = {"Item 1", "Item 2", "Item 3"};
	LinearView lv = {
		.listbox = NULL,
		.fixed = fixed,
		.largura = 300,
		.altura = 200,
		.x = 50,
		.y = 50,
		.item_height = 30,
		.item_width = 100,
		.item_count = 3,
		.items = items,
		.item_clicked_callback = test_callback,
		.callback_data = "100",
		.vertical = TRUE,
		.visivel = TRUE,
		.background_color = "ffffff",
		.item_color = "333333",
		.border_width = 1,
		.border_color = "664aaa"
	};

	init_linear_view(&lv);
	set_window_background(window, TAN);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

/*
int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Exemplo de LinearView");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	GtkWidget *fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	char *items[] = {"Item 1", "Item 2", "Item 3"};

	LinearView lv;
	lv.listbox = NULL;
	lv.fixed = fixed;
	lv.largura = 300;
	lv.altura = 200;
	lv.x = 50;
	lv.y = 50;
	lv.item_height = 200;
	lv.item_width = 200;
	lv.item_count = 3;
	lv.items = items;
	lv.item_clicked_callback = on_item_clicked;
	lv.callback_data = NULL;
	lv.dados_adicionais = NULL;
	lv.visivel = 1;
	lv.vertical = TRUE; // Definir para FALSE para disposição horizontal
	lv.background_color = "#333333"; // Cor de fundo do ListBox
	lv.item_color = "#ff0000";       // Cor do texto dos itens
	lv.border_width = 4;             // Largura da borda dos itens
	lv.border_color = "#ffffff";

	iniit_linear_view(&lv);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}*/

/*
void init_linear_view(LinearView *lv) {
    if (!lv || !lv->fixed) {
        fprintf(stderr, "LinearView ou contêiner inválido.\n");
        return;
    }

    if (!lv->listbox) {
        lv->listbox = gtk_list_box_new();
        gtk_fixed_put(GTK_FIXED(lv->fixed), lv->listbox, lv->x, lv->y);
    }

    // Configura o tamanho da lista
    gtk_widget_set_size_request(lv->listbox, lv->largura > 0 ? lv->largura : 200, lv->altura > 0 ? lv->altura : 300);

    // Adiciona itens à lista com disposição linear
    for (int i = 0; i < lv->item_count; ++i) {
        GtkWidget *row = gtk_box_new(lv->vertical ? GTK_ORIENTATION_VERTICAL : GTK_ORIENTATION_HORIZONTAL, 0);
        GtkWidget *label = gtk_label_new(lv->items[i]);
        gtk_box_pack_start(GTK_BOX(row), label, TRUE, TRUE, 0);
        gtk_list_box_insert(GTK_LIST_BOX(lv->listbox), row, -1);
    }

    // Define a altura ou largura dos itens dependendo da disposição
    if (lv->vertical) {
        gtk_widget_set_size_request(lv->listbox, lv->largura > 0 ? lv->largura : 200, lv->item_height > 0 ? lv->item_height * lv->item_count : 300);
    } else {
        gtk_widget_set_size_request(lv->listbox, lv->item_width > 0 ? lv->item_width * lv->item_count : 300, lv->altura > 0 ? lv->altura : 200);
    }

    // Conecta o sinal de clique do item
    if (lv->item_clicked_callback) {
        g_signal_connect(lv->listbox, "row-activated", G_CALLBACK(lv->item_clicked_callback), lv->callback_data);
    }

    // Define a visibilidade
    if (lv->visivel == 1) {
        gtk_widget_show(lv->listbox);
    } else {
        gtk_widget_hide(lv->listbox);
    }
}




void init_linear_view(LinearView *lv);
void on_item_clicked(GtkWidget *widget, gpointer data);

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Exemplo de LinearView");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    LinearView lv;
    lv.listbox = NULL;
    lv.fixed = fixed;
    lv.largura = 300;
    lv.altura = 200;
    lv.x = 50;
    lv.y = 50;
    lv.item_height = 30;
    lv.item_width = 100;
    lv.item_count = 3;
    lv.items = (char *[]){"Item 1", "Item 2", "Item 3"};
    lv.item_clicked_callback = on_item_clicked;
    lv.callback_data = NULL;
    lv.visivel = 1;
    lv.vertical = FALSE; // Definir para FALSE para disposição horizontal

    init_linear_view(&lv);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}



void init_list_view(ListView *lv);

void on_item_clicked(GtkWidget *widget, gpointer data) {
    GtkListBoxRow *row = GTK_LIST_BOX_ROW(widget);
    GtkWidget *label = gtk_bin_get_child(GTK_BIN(row));
    const gchar *text = gtk_label_get_text(GTK_LABEL(label));
    g_print("Item clicado: %s\n", text);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Exemplo de GtkListBox");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    ListView lv;
    lv.listbox = NULL;
    lv.fixed = fixed;
    lv.largura = 300;
    lv.altura = 200;
    lv.x = 50;
    lv.y = 50;
    lv.item_height = 30;
    lv.item_count = 3;
    lv.items = (char *[]){"Item 1", "Item 2", "Item 3"};
    lv.item_clicked_callback = on_item_clicked;
    lv.callback_data = NULL;
    lv.visivel = 1;

    init_list_view(&lv);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

void	init_text_viiew(TextView *tv)
{
	GtkCssProvider	*css_provider;
	GtkStyleContext	*context;
	char			css[256];

	if (!tv || !tv->fixed)
	{
		fprintf(stderr, "TextView ou contêiner inválido.\n");
		return ;
	}
	if (!tv->Ob)
	{
		tv->Ob = gtk_text_view_new();
		gtk_fixed_put(GTK_FIXED(tv->fixed), tv->Ob, tv->x, tv->y);
	}

	GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv->Ob));
	if (tv->texto)
		gtk_text_buffer_set_text(buffer, tv->texto, -1);

	gtk_widget_set_size_request(tv->Ob,
		tv->largura > 0 ? tv->largura : 200,
		tv->altura > 0 ? tv->altura : 100);

	gtk_widget_set_name(tv->Ob, "text_view");

	css_provider = gtk_css_provider_new();
	snprintf(css, sizeof(css),
		"#text_view { "
		"background-color: #%06x; "
		"color: #%06x; "
		"border: %dpx solid #%06x; "
		"}",
		tv->cor, tv->textcor, tv->bord, tv->bcor);
	gtk_css_provider_load_from_data(css_provider, css, -1, NULL);

	context = gtk_widget_get_style_context(tv->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(css_provider);

	if (tv->visivel == VISIVEL)
		gtk_widget_show(tv->Ob);
	else if (tv->visivel == INVISIVEL)
		gtk_widget_hide(tv->Ob);
	else
	{
		gtk_widget_destroy(tv->Ob);
		tv->Ob = NULL;
	}
}


int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = create_window("Teste do GtkTextView", 600, 500, FALSE);

    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    TextView tv;
    tv.Ob = NULL;
    tv.fixed = fixed;
    tv.texto = "Texto de teste";
    tv.largura = 300;
    tv.altura = 200;
    tv.x = 50;
    tv.y = 50;
    tv.cor = 0xFFFFFF; // branco
    tv.textcor = 0x000000; // preto
    tv.bord = 1;
    tv.bcor = 0x000000; // preto
    tv.visivel = VISIVEL;

    init_text_viiew(&tv);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *fixed;
	GtkWidget *bb;

	gtk_init(&argc, &argv);
	window =  create_window("Exemplo de Interface", 680, 520, TRUE);

	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	Butoon b1 = { .fixed = fixed, .x = 50, .y = 50, .texto = "Clique Aqui", .visivel = VISIVEL };
	b1.textcor = 0x00ff00;
	b1.largura = 200;
	b1.bord = 8;
	init_butoon(&b1);

	// Inicializando e adicionando uma label
	Label label = { .fixed = fixed, .x = 50, .y = 100, .texto = "Olá, Mundo!", .visivel = INVISIVEL };
	label.textcor = 0x00ff00;
	label.cor = 0xffffff;
	label.bcor = 0x0000ff;
	label.bord = 8;
	init_label(&label);

	// Inicializando e adicionando uma entrada de texto
	Edtext entry = { .fixed = fixed, .x = 50, .y = 150, .texto = "Texto aqui", .visivel = VISIVEL };
	entry.largura = 200;
	entry.altura = 100;
	entry.textcor = 0xffffff;
	entry.cor = 0x000000;
	entry.bcor = 0x0000ff;
	entry.bord = 8;
	init_entry(&entry);
	
	TextView tv;
	tv.fixed = fixed;
	tv.texto = " Seu texto ";
	tv.largura = 300;
	tv.altura = 150;
	tv.x = 10;
	tv.y = 10;
	tv.cor = 0xFFFFFF; // Cor de fundo
	tv.textcor = 0x000000; // Cor do texto
	tv.bord = 1; // Espessura da borda
	tv.bcor = 0xCCCCCC; // Cor da borda
	tv.visivel = VISIVEL;

    init_text_view(&tv);*/
	//GtkFixed *g = initialize_layout(window);
	
	//create_image(g, "l.png", 55, 55);

	/*GtkWidget *image = gtk_image_new_from_file(file_path);
	gtk_fixed_put(fixed, image, x, y);*/


	/*Separator sep;
	sep.visivel = VISIVEL;
	sep.fixed = fixed;
	sep.x = 10;
	sep.y = 50;
	sep.largura = 500;
	sep.altura = 6;
	sep.cor = 0x0000ff;
	init_separator(&sep);
	
	Separator sp;
	sp.visivel = VISIVEL;
	sp.fixed = fixed;
	sp.x = 10;
	sp.y = 100;
	sp.largura = 500;
	sp.altura = 6;
	sp.cor = 0xff00ff;
	init_separator(&sp);

	Imagem imagem;
	imagem.fixed = fixed;
	imagem.Ob = NULL;
	imagem.x = 300;
	imagem.y = 50;
	imagem.cor = 0x0000ff;
	//imagem.largura = 150;
	//imagem.altura = 150;
	imagem.file_path = "l.png";
	imagem.bord = 2;
	imagem.visivel = VISIVEL;
	init_imagem(&imagem);
	
	Imagem image;
	image.fixed = fixed;
	image.Ob = NULL;
	image.x = 30;
	image.y = 70;
	image.cor = 0x00ffff;
	image.largura = 90;
	image.altura = 10;
	image.file_path = "l.png";
	image.bord = 2;
	image.visivel = VISIVEL;
	init_imagem(&image);
	
	Imagem imag;
	imag.fixed = fixed;
	imag.Ob = NULL;
	imag.x = 0;
	imag.y = 0;
	imag.cor = 0x000000;
	imag.largura = 90;
	imag.altura = 10;
	imag.file_path = "p.png";
	imag.bord = 2;
	imag.visivel = VISIVEL;
	init_imagem(&imag);
	
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

typedef struct s_label
{
    GtkWidget *Ob;         // O próprio widget Label
    GtkFixed *fixed;       // Contêiner onde o widget é colocado
    int x;                 // Coordenada X
    int y;                 // Coordenada Y
    int largura;           // Largura do widget
    int altura;            // Altura do widget
    char *texto;           // Texto do Label
    int cor;               // Cor de fundo (em formato hexadecimal)
    int textcor;           // Cor do texto (em formato hexadecimal)
    Status visivel;        // Visibilidade
} Label;

void	init_label(Label *lbl)
{
	if (!lbl || !lbl->fixed)
	{
		fprintf(stderr, "Label ou contêiner inválido.\n");
	return;
	}

	if (!lbl->Ob)
	{
		lbl->Ob = gtk_label_new(NULL);
		gtk_fixed_put(GTK_FIXED(lbl->fixed), lbl->Ob, lbl->x, lbl->y);
	}

	gtk_label_set_text(GTK_LABEL(lbl->Ob), lbl->texto ? lbl->texto : "Label");
	gtk_widget_set_size_request(lbl->Ob, lbl->largura > 0 ? lbl->largura : 100, lbl->altura > 0 ? lbl->altura : 50);

	GtkCssProvider *provider = gtk_css_provider_new();
	gchar css[256];
	g_snprintf(css, sizeof(css),
		"label { "
		"background-color: #%06x; "
		"color: #%06x; "
		"}", 
		lbl->cor ? lbl->cor : 0xFFFFFF,
		lbl->textcor ? lbl->textcor : 0x000000);

	gtk_css_provider_load_from_data(provider, css, -1, NULL);
	GtkStyleContext *context = gtk_widget_get_style_context(lbl->Ob);
	gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	g_object_unref(provider);

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

void init_entry(Entry *ent)
{
    if (!ent || !ent->fixed)
    {
        fprintf(stderr, "Entry ou contêiner inválido.\n");
        return;
    }

    // Cria o Entry se ainda não estiver criado
    if (!ent->Ob)
    {
        ent->Ob = gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(ent->fixed), ent->Ob, ent->x, ent->y);
    }

    // Define o texto inicial do Entry
    gtk_entry_set_text(GTK_ENTRY(ent->Ob), ent->texto ? ent->texto : "");

    // Define o tamanho do Entry
    gtk_widget_set_size_request(ent->Ob, ent->largura > 0 ? ent->largura : 100, ent->altura > 0 ? ent->altura : 25);

    // Cria um CSS provider para aplicar o estilo
    GtkCssProvider *provider = gtk_css_provider_new();
    gchar css[256];
    g_snprintf(css, sizeof(css),
               "entry { "
               "border-width: %dpx; "
               "border-color: #%06x; "
               "border-style: solid; "
               "}", 
               ent->bord > 0 ? ent->bord : 1,    // Espessura da borda padrão: 1px
               ent->bcor ? ent->bcor : 0x000000); // Cor da borda padrão: preto

    gtk_css_provider_load_from_data(provider, css, -1, NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(ent->Ob);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider); // Libera o CSS provider

    // Define a visibilidade do Entry
    if (ent->visivel == VISIVEL)
    {
        gtk_widget_show(ent->Ob);
    }
    else if (ent->visivel == INVISIVEL)
    {
        gtk_widget_hide(ent->Ob);
    }
    else
    {
        gtk_widget_destroy(ent->Ob);
        ent->Ob = NULL; // Define o ponteiro como NULL após destruir
    }
}

void init_image(Image *img)
{
    if (!img || !img->fixed)
    {
        fprintf(stderr, "Image ou contêiner inválido.\n");
        return;
    }

    // Cria a Image se ainda não estiver criada
    if (!img->Ob)
    {
        img->Ob = gtk_image_new_from_file(img->file_path);
        gtk_fixed_put(GTK_FIXED(img->fixed), img->Ob, img->x, img->y);
    }

    // Define o tamanho da Image
    gtk_widget_set_size_request(img->Ob, img->largura > 0 ? img->largura : 100, img->altura > 0 ? img->altura : 100);

    // Define a visibilidade da Image
    if (img->visivel == VISIVEL)
    {
        gtk_widget_show(img->Ob);
    }
    else if (img->visivel == INVISIVEL)
    {
        gtk_widget_hide(img->Ob);
    }
    else
    {
        gtk_widget_destroy(img->Ob);
        img->Ob = NULL; // Define o ponteiro como NULL após destruir
    }
}

void init_drawing_area(DrawingArea *da)
{
    if (!da || !da->fixed)
    {
        fprintf(stderr, "DrawingArea ou contêiner inválido.\n");
        return;
    }

    // Cria o DrawingArea se ainda não estiver criado
    if (!da->Ob)
    {
        da->Ob = gtk_drawing_area_new();
        gtk_fixed_put(GTK_FIXED(da->fixed), da->Ob, da->x, da->y);
    }

    // Define o tamanho do DrawingArea
    gtk_widget_set_size_request(da->Ob, da->largura > 0 ? da->largura : 100, da->altura > 0 ? da->altura : 100);

    // Conecta o callback de desenho
    if (da->draw_callback)
    {
        g_signal_connect(G_OBJECT(da->Ob), "draw", G_CALLBACK(da->draw_callback), da->data);
    }

    // Define a visibilidade do DrawingArea
    if (da->visivel == VISIVEL)
    {
        gtk_widget_show(da->Ob);
    }
    else if (da->visivel == INVISIVEL)
    {
        gtk_widget_hide(da->Ob);
    }
    else
    {
        gtk_widget_destroy(da->Ob);
        da->Ob = NULL; // Define o ponteiro como NULL após destruir
    }
}

#include "libsf.h"

// Função de callback para o DrawingArea
gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Cor azul
    cairo_paint(cr);
    return FALSE;
}

// Função para criar a janela e adicionar widgets
void create_and_show_widgets()
{
	GtkWidget *window;
	GtkFixed *fixed;
	Label lbl;
	Entry ent;
	Image img;
	DrawingArea da;

	// Inicializa GTK
	gtk_init(NULL, NULL);

	// Cria a janela principal
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Teste de Widgets");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

	// Cria o contêiner Fixed e adiciona à janela
	fixed = GTK_FIXED(gtk_fixed_new());
	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(fixed));

	// Inicializa e configura o Label
	lbl.Ob = NULL;
	lbl.fixed = fixed;
	lbl.x = 10;
	lbl.y = 10;
	lbl.largura = 200;
	lbl.altura = 50;
	lbl.texto = "Olá Mundo";
	lbl.cor = 0xffffff; // Cor de fundo
	lbl.textcor = 0x0000FF; // Cor do texto
	lbl.visivel = VISIVEL;
	init_label(&lbl);

	// Inicializa e configura o Entry
	ent.Ob = NULL;
	ent.fixed = fixed;
	ent.x = 10;
	ent.y = 70;
	ent.largura = 200;
	ent.altura = 30;
	ent.texto = "Digite aqui";
	ent.bord = 2;
	ent.bcor = 0xff0000; // Cor da borda
	ent.visivel = VISIVEL;
	init_entry(&ent);

	// Inicializa e configura a Image
	img.Ob = NULL;
	img.fixed = fixed;
	img.x = 10;
	img.y = 110;
	img.largura = 50;
	img.altura = 50;
	img.file_path = "e.png";
	img.visivel = VISIVEL;
	init_image(&img);

	da.Ob = NULL;
	da.fixed = fixed;
	da.x = 10;
	da.y = 270;
	da.largura = 200;
	da.altura = 150;
	da.draw_callback = on_draw;
	da.data = NULL;
	da.visivel = VISIVEL;
	init_drawing_area(&da);


	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);

	gtk_main();
}

int main(int argc, char *argv[])
{
    create_and_show_widgets();
    return 0;
}



int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Janela com Cor de Fundo Personalizada");
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

	set_window_background(window, 0x00FF);
	GtkFixed *fixed = GTK_FIXED(gtk_fixed_new());
	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(fixed));

	Butoon b1 = {
		.texto = "Olá Mundo ii",
		.cor = 0xff0000,        // Cor de fundo
		.largura = 250,       // Largura
		.altura = 50,         // Altura
		.visivel = INVISIVEL,   // Estado visível
		.trans = 100,        // Transparência
		.textcor = 0x00ff00, // Cor do texto
		.bord = 8,           // Espessura da borda
		.bcor = 0xff0000,   // Cor da borda
		.x = 40,            // Coordenada X
		.y = 20,            // Coordenada Y
		.fixed = fixed,     // Contêiner fixo
		.Ob = NULL          // Inicialmente nulo
	};

	init_butoon(&b1);

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Exemplo de Botão");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkFixed *fixed = GTK_FIXED(gtk_fixed_new());
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(fixed));

    Butoon b1 = {
        .texto = "Olá Mundo ii",
        .cor = 0xff0000,        // Cor de fundo
        .largura = 250,       // Largura
        .altura = 50,         // Altura
        .visivel = INVISIVEL,   // Estado visível
        .trans = 100,        // Transparência
        .textcor = 0x00ff00, // Cor do texto
        .bord = 8,           // Espessura da borda
        .bcor = 0xff0000,   // Cor da borda
        .x = 40,            // Coordenada X
        .y = 20,            // Coordenada Y
        .fixed = fixed,     // Contêiner fixo
        .Ob = NULL          // Inicialmente nulo
    };

    init_butoon(&b1);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
*/
