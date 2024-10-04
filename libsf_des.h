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


// Definir fonte diretamente na descrição da fonte do label
#define label_set_font_desc(lbl, desc) \
	gtk_widget_override_font(GTK_WIDGET(lbl), desc)

// Definir fonte usando uma string com o nome da fonte
#define label_set_font_from_string(lbl, font_desc_str) \
	do { \
		PangoFontDescription *desc = pango_font_description_from_string(font_desc_str); \
		label_set_font_desc(lbl, desc); \
		pango_font_desc_free(desc); \
	} while (0)

// Definir família da fonte (somente)
#define label_set_font_family(lbl, family) \
	do { \
		PangoFontDescription *desc = gtk_widget_get_pango_context(GTK_WIDGET(lbl)); \
		pango_font_description_set_family(desc, family); \
		label_set_font_desc(lbl, desc); \
	} while (0)

// Definir tamanho da fonte
#define label_set_font_size(lbl, size) \
	do { \
		PangoFontDescription *desc = gtk_widget_get_pango_context(GTK_WIDGET(lbl)); \
		pango_font_description_set_size(desc, size * PANGO_SCALE); \
		label_set_font_desc(lbl, desc); \
	} while (0)

// Definir estilo da fonte (normal, itálico, oblíquo)
#define label_set_font_style(lbl, style) \
	do { \
		PangoFontDescription *desc = gtk_widget_get_pango_context(GTK_WIDGET(lbl)); \
		pango_font_description_set_style(desc, style); \
		label_set_font_desc(lbl, desc); \
	} while (0)

// Definir peso da fonte (leve, normal, negrito)
#define label_set_font_weight(lbl, weight) \
	do { \
		PangoFontDescription *desc = gtk_widget_get_pango_context(GTK_WIDGET(lbl)); \
		pango_font_description_set_weight(desc, weight); \
		label_set_font_desc(lbl, desc); \
	} while (0)

// Definir alinhamento do texto dentro do label
#define label_set_alignment(lbl, xalign, yalign) \
	gtk_label_set_xalign(GTK_LABEL(lbl), xalign); \
	gtk_label_set_yalign(GTK_LABEL(lbl), yalign)

// Definir espaçamento entre linhas no texto do label
#define label_set_line_spacing(lbl, spacing) \
	gtk_label_set_line_spacing(GTK_LABEL(lbl), spacing)

// Definir o número máximo de linhas de exibição no label
#define label_set_max_lines(lbl, max_lines) \
	gtk_label_set_max_width_chars(GTK_LABEL(lbl), max_lines)

// Definir se o texto do label deve ser sublinhado
#define label_set_underline(lbl, underline) \
	gtk_label_set_underline(GTK_LABEL(lbl), underline)
	
// Remover widget de um GtkBox
#define box_remove(box, widget) \
	gtk_container_remove(GTK_CONTAINER(box), widget)

// Definir alinhamento do widget dentro do GtkBox
#define box_set_alignment(widget, xalign, yalign) \
	do { \
		gtk_widget_set_halign(GTK_WIDGET(widget), xalign); \
		gtk_widget_set_valign(GTK_WIDGET(widget), yalign); \
	} while (0)

// Definir a cor de fundo de um widget
#define widget_set_background_color(widget, r, g, b) \
	do { \
		GdkRGBA color = {r, g, b, 1.0}; \
		gtk_widget_override_background_color(GTK_WIDGET(widget), GTK_STATE_FLAG_NORMAL, &color); \
	} while (0)

// Definir a cor do texto de um widget
#define widget_set_text_color(widget, r, g, b) \
	do { \
		GdkRGBA color = {r, g, b, 1.0}; \
		gtk_widget_override_color(GTK_WIDGET(widget), GTK_STATE_FLAG_NORMAL, &color); \
	} while (0)

// Definir a cor da borda de um widget
#define widget_set_border_color(widget, r, g, b) \
	do { \
		GdkRGBA color = {r, g, b, 1.0}; \
		gtk_widget_override_color(GTK_WIDGET(widget), GTK_STATE_FLAG_NORMAL, &color); \
		gtk_widget_override_background_color(GTK_WIDGET(widget), GTK_STATE_FLAG_NORMAL, &color); \
	} while (0)

// Definir a cor do foco (highlight) de um widget
#define widget_set_focus_color(widget, r, g, b) \
	do { \
		GdkRGBA color = {r, g, b, 1.0}; \
		gtk_widget_override_color(GTK_WIDGET(widget), GTK_STATE_FLAG_FOCUS, &color); \
	} while (0)

// Definir a cor de um widget em estado ativo (pressed)
#define widget_set_active_color(widget, r, g, b) \
	do { \
		GdkRGBA color = {r, g, b, 1.0}; \
		gtk_widget_override_color(GTK_WIDGET(widget), GTK_STATE_FLAG_ACTIVE, &color); \
	} while (0)

// Definir a cor de um widget em estado de desabilitado
#define widget_set_disabled_color(widget, r, g, b) \
	do { \
		GdkRGBA color = {r, g, b, 1.0}; \
		gtk_widget_override_color(GTK_WIDGET(widget), GTK_STATE_FLAG_INSENSITIVE, &color); \
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



// Funções de Manipulação de Label
#define set_text(lbl, txt) gtk_label_set_text(GTK_LABEL(lbl), txt)
#define get_text(lbl) gtk_label_get_text(GTK_LABEL(lbl))

#define set_markup(lbl, markup) gtk_label_set_markup(GTK_LABEL(lbl), markup)

#define set_justify(lbl, j) gtk_label_set_justify(GTK_LABEL(lbl), j)

#define set_xalign(lbl, x) gtk_label_set_xalign(GTK_LABEL(lbl), x)

#define set_yalign(lbl, y) gtk_label_set_yalign(GTK_LABEL(lbl), y)

#define set_line_wrap(lbl, wrap) gtk_label_set_line_wrap(GTK_LABEL(lbl), wrap)

#define set_ellipsize(lbl, mode) gtk_label_set_ellipsize(GTK_LABEL(lbl), mode)

#define set_max_width(lbl, chars) gtk_label_set_max_width_chars(GTK_LABEL(lbl), chars)

#define set_angle(lbl, ang) gtk_label_set_angle(GTK_LABEL(lbl), ang)

#define set_width(lbl, chars) gtk_label_set_width_chars(GTK_LABEL(lbl), chars)

#define set_single_line(lbl, mode) gtk_label_set_single_line_mode(GTK_LABEL(lbl), mode)

#define set_attrs(lbl, attrs) gtk_label_set_attributes(GTK_LABEL(lbl), attrs)

#define get_max_width(lbl) gtk_label_get_max_width_chars(GTK_LABEL(lbl))

#define get_use_markup(lbl) gtk_label_get_use_markup(GTK_LABEL(lbl))

#define set_use_markup(lbl, use) gtk_label_set_use_markup(GTK_LABEL(lbl), use)

#define set_selectable(lbl, sel) gtk_label_set_selectable(GTK_LABEL(lbl), sel)

#define get_selectable(lbl) gtk_label_get_selectable(GTK_LABEL(lbl))

#define set_mnemonic(lbl, widget) gtk_label_set_mnemonic_widget(GTK_LABEL(lbl), widget)

#define get_mnemonic(lbl) gtk_label_get_mnemonic_widget(GTK_LABEL(lbl))

#define get_angle(lbl) gtk_label_get_angle(GTK_LABEL(lbl))

#define get_use_underline(lbl) gtk_label_get_use_underline(GTK_LABEL(lbl))

#define set_use_underline(lbl, use) gtk_label_set_use_underline(GTK_LABEL(lbl), use)

#define get_justify(lbl) gtk_label_get_justify(GTK_LABEL(lbl))

#define get_line_wrap_mode(lbl) gtk_label_get_line_wrap_mode(GTK_LABEL(lbl))

// Funções de Manipulação de Box
#define set_homogeneous(box, homo) gtk_box_set_homogeneous(GTK_BOX(box), homo)
#define get_homogeneous(box) gtk_box_get_homogeneous(GTK_BOX(box))
#define set_spacing(box, space) gtk_box_set_spacing(GTK_BOX(box), space)
#define get_spacing(box) gtk_box_get_spacing(GTK_BOX(box))
#define set_baseline_pos(box, pos) gtk_box_set_baseline_position(GTK_BOX(box), pos)
#define get_baseline_pos(box) gtk_box_get_baseline_position(GTK_BOX(box))
#define insert_after(box, child, sibling) gtk_box_insert_child_after(GTK_BOX(box), child, sibling)
#define insert_before(box, child, sibling) gtk_box_insert_child_before(GTK_BOX(box), child, sibling)
#define reorder_child(box, child, pos) gtk_box_reorder_child(GTK_BOX(box), child, pos)
#define remove_child(box, child) gtk_box_remove(GTK_BOX(box), child)
#define get_child_at(box, idx) gtk_box_get_child_at_index(GTK_BOX(box), idx)

// Funções para Manipular Outros Widgets
#define set_margin_top(widget, mtop) gtk_widget_set_margin_top(widget, mtop)
#define set_margin_bottom(widget, mbot) gtk_widget_set_margin_bottom(widget, mbot)
#define set_margin_start(widget, mstart) gtk_widget_set_margin_start(widget, mstart)
#define set_margin_end(widget, mend) gtk_widget_set_margin_end(widget, mend)
#define set_valign(widget, align) gtk_widget_set_valign(widget, align)
#define set_halign(widget, align) gtk_widget_set_halign(widget, align)
#define get_valign(widget) gtk_widget_get_valign(widget)
#define get_halign(widget) gtk_widget_get_halign(widget)
#define set_opacity(widget, opac) gtk_widget_set_opacity(widget, opac)
#define get_opacity(widget) gtk_widget_get_opacity(widget)
#define set_size(widget, width, height) gtk_widget_set_size_request(widget, width, height)
#define set_visible(widget, vis) gtk_widget_set_visible(widget, vis)
#define set_sensitive(widget, sens) gtk_widget_set_sensitive(widget, sens)
#define grab_focus(widget) gtk_widget_grab_focus(widget)
#define show(widget) gtk_widget_show(widget)


#endif
