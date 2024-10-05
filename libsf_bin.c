
# include "libsf.h"
# include "libsf_run.h"

typedef struct
{
	int button; // Número do botão do mouse
	void (*func)(GtkWidget*, void*); // Função a ser chamada no evento
	void *pointer; // Ponteiro para dados adicionais
} dataste;

// Função chamada ao pressionar um botão do mouse
static void on_button_press_event(GtkWidget *widget, GdkEventButton *event, gpointer data)
{
	dataste *tup = (dataste *)data;
	if (event->button == tup->button)
		tup->func(widget, tup->pointer);
}

// Configura um evento de clique do mouse em um widget
void mause_click(GtkWidget *widget, int button, void (*func)(GtkWidget*, void*), void *pointer)
{
	dataste *tup = g_new(dataste, 1);
	tup->func = func;
	tup->button = button;
	tup->pointer = pointer;
	g_signal_connect(widget, "button-press-event", G_CALLBACK(on_button_press_event), tup);
}


GtkWidget*	sf_new_button(const char *label)
{
	return (gtk_button_new_with_label(label));
}

void	sf_set_button_label(GtkWidget *button, const char *label)
{
	gtk_button_set_label(GTK_BUTTON(button), label);
}

void	sf_set_name(GtkWidget *widget, const char *name)
{
	gtk_widget_set_name(widget, name);
}

void	sf_add_style(GtkStyleContext *context, GtkStyleProvider *provider, GtkStyleProvider_autoptr priority)
{
	gtk_style_context_add_provider(context, provider, priority);
}

GtkWidget*	sf_new_image(const char *filename)
{
	return (gtk_image_new_from_file(filename));	
}

GtkWidget*	sf_new_progress(void)
{
	return gtk_progress_bar_new();
}

void	sf_set_radio_group(GtkRadioButton *radio_button, GSList *group)
{
	gtk_radio_button_set_group(radio_button, group);
}

void	print_fixed(GtkWidget *fixed, GtkWidget *widget, int x, int y)
{
	gtk_fixed_put(GTK_FIXED(fixed), widget, x, y);
}

GtkWidget*	sf_new_label(const char *label)
{
	return gtk_label_new(label);
}

GtkWidget*	sf_new_window(GtkWindowType type)
{
	return gtk_window_new(type);
}

GtkWidget*	sf_new_EText(void)
{
	return gtk_entry_new();
}

GtkWidget*	sf_new_toggle(void)
{
	return gtk_toggle_button_new();
}

GtkWidget*	sf_new_combo(void)
{
	return gtk_combo_box_text_new();
}

void	sf_pack_start(GtkBox *box, GtkWidget *widget, gboolean expand, gboolean fill, guint padding)
{
	gtk_box_pack_start(box, widget, expand, fill, padding);
}

void	sf_show_all(GtkWidget *widget)
{
	gtk_widget_show_all(widget);
}

void	sf_add_to_container(GtkContainer *container, GtkWidget *widget)
{
	gtk_container_add(container, widget);
}

GtkWidget*	sf_new_tree_view(void)
{
	return gtk_tree_view_new();
}

void	sf_append_column(GtkTreeView *tree_view, GtkTreeViewColumn *column)
{
	gtk_tree_view_append_column(tree_view, column);
}

GtkWidget*	sf_new_file_dialog(GtkWindow *parent, const char *title, GtkFileChooserAction action)
{
	return gtk_file_chooser_dialog_new(title, parent, action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open", GTK_RESPONSE_ACCEPT, NULL);
}

int	sf_run_dialog(GtkDialog *dialog)
{
	return gtk_dialog_run(dialog);
}

void	sf_destroy_widget(GtkWidget *widget)
{
	gtk_widget_destroy(widget);
}

void	sf_main_loop(void)
{
	gtk_main();
}

void	sf_quit(void)
{
	gtk_main_quit();
}

GtkWidget*	sf_new_menu_item(const char *label)
{
	return gtk_menu_item_new_with_label(label);
}

GtkWidget*	sf_new_scrolled_window(void)
{
	return gtk_scrolled_window_new(NULL, NULL);
}

GtkWidget*	sf_new_paned(void)
{
	return gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
}

GtkWidget*	sf_new_scale(GtkOrientation orientation)
{
	return gtk_scale_new(orientation, NULL);
}

GtkWidget*	sf_new_spin(double min, double max, double step)
{
	return gtk_spin_button_new_with_range(min, max, step);
}
GtkWidget*	sf_color_dialog(const char *title, GtkWindow *parent)
{
	return gtk_color_chooser_dialog_new(title, parent);
}

GtkWidget*	sf_font_dialog(const char *title, GtkWindow *parent)
{
	return gtk_font_chooser_dialog_new(title, parent);
}

GtkWidget*	sf_new_box(GtkOrientation orientation)
{
	return gtk_box_new(orientation, 0);
}

GtkWidget*	sf_new_button_with_icon(const char *icon_name)
{
	return gtk_button_new_from_icon_name(icon_name, GTK_ICON_SIZE_BUTTON);
}

void	sf_set_widget_size(GtkWidget *widget, int width, int height)
{
	gtk_widget_set_size_request(widget, width, height);
}

void	sf_set_widget_visibility(GtkWidget *widget, gboolean visible)
{
	if (visible)
		gtk_widget_show(widget);
	else
		gtk_widget_hide(widget);
}

void	sf_set_widget_sensitive(GtkWidget *widget, gboolean sensitive)
{
	gtk_widget_set_sensitive(widget, sensitive);
}

void	sf_set_widget_margin(GtkWidget *widget, int margin)
{
	gtk_widget_set_margin_start(widget, margin);
	gtk_widget_set_margin_end(widget, margin);
	gtk_widget_set_margin_top(widget, margin);
	gtk_widget_set_margin_bottom(widget, margin);
}

GtkWidget*	sf_new_check_button(const char *label)
{
	return gtk_check_button_new_with_label(label);
}

GtkWidget*	sf_new_separator(GtkOrientation orientation)
{
	return gtk_separator_new(orientation);
}

void	sf_set_text(GtkLabel *label, const char *text)
{
	gtk_label_set_text(label, text);
}

GtkWidget*	sf_new_spinner(void)
{
	return gtk_spinner_new();
}

void	sf_start_spinner(GtkSpinner *spinner)
{
	gtk_spinner_start(spinner);
}

void	sf_stop_spinner(GtkSpinner *spinner)
{
	gtk_spinner_stop(spinner);
}

GtkWidget*	sf_new_image_from_pixbuf(GdkPixbuf *pixbuf)
{
	return gtk_image_new_from_pixbuf(pixbuf);
}

GtkWidget*	sf_new_adjustment(double value, double lower, double upper, double step_increment, double page_increment, double page_size)
{
	return gtk_adjustment_new(value, lower, upper, step_increment, page_increment, page_size);
}

void	sf_set_adjustment(GtkAdjustment *adjustment, double value, double lower, double upper, double step_increment, double page_increment, double page_size)
{
	gtk_adjustment_set_value(adjustment, value);
	gtk_adjustment_set_lower(adjustment, lower);
	gtk_adjustment_set_upper(adjustment, upper);
	gtk_adjustment_set_step_increment(adjustment, step_increment);
	gtk_adjustment_set_page_increment(adjustment, page_increment);
	gtk_adjustment_set_page_size(adjustment, page_size);
}

GtkWidget*	sf_new_scrolled_window_with_adjusments(GtkAdjustment *hadjustment, GtkAdjustment *vadjustment)
{
	return gtk_scrolled_window_new(hadjustment, vadjustment);
}

GtkWidget*	sf_new_drawing_area(void)
{
	return gtk_drawing_area_new();
}

void	sf_set_drawing_area_size(GtkDrawingArea *drawing_area, int width, int height)
{
	gtk_widget_set_size_request(GTK_WIDGET(drawing_area), width, height);
}

GtkWidget*	sf_new_EText_with_placeholder(const char *placeholder)
{
	GtkWidget *entry = gtk_entry_new();
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholder);
	return entry;
}

GtkWidget*	sf_new_scale_with_range(GtkOrientation orientation, double min, double max, double step)
{
	return gtk_scale_new_with_range(orientation, min, max, step);
}

void	sf_set_scale_value(GtkScale *scale, double value)
{
	gtk_range_set_value(GTK_RANGE(scale), value);
}

GtkWidget*	sf_new_notebook(void)
{
	return gtk_notebook_new();
}

void	sf_add_notebook_page(GtkNotebook *notebook, GtkWidget *child, const char *tab_label)
{
	gtk_notebook_append_page(notebook, child, gtk_label_new(tab_label));
}
/* ************renomiadas************** */

const char* get_text_button(GtkWidget *button)
{
	return gtk_button_get_label(GTK_BUTTON(button));
}

const char* get_name(GtkWidget *widget)
{
	return gtk_widget_get_name(widget);
}

/*GtkStyleProvider* get_style(GtkStyleContext *context)
{
	return gtk_style_context_add_provider(context);	
}*/

GdkPixbuf* get_image_pixbuf(GtkImage *image)
{
	return gtk_image_get_pixbuf(image);
}

gdouble get_progress_value(GtkProgressBar *progress_bar)
{
	return gtk_progress_bar_get_fraction(progress_bar);
}

GSList* get_radio_group(GtkRadioButton *radio_button)
{
	return gtk_radio_button_get_group(radio_button);
}
/*
void get_fixed_position(GtkWidget *fixed, GtkWidget *widget, int *x, int *y)
{
	gtk_fixed_get_type(GTK_FIXED(fixed), "children", &widget);
	gtk_widget_get_allocation(widget, x, y);
}
*/
const char*	get_label(GtkWidget *label)
{
	return gtk_label_get_text(GTK_LABEL(label));	
}

/*GType	get_window_type(GtkWidget *window)
{
	return gtk_window_get_type(GTK_WINDOW(window));
}
*/
const char*	get_entry_text(GtkEntry *entry)
{
	return gtk_entry_get_text(entry);
}

gboolean	get_toggle_state(GtkToggleButton *toggle)
{
	return gtk_toggle_button_get_active(toggle);
}

GtkWidget*	get_combo_active(GtkComboBoxText *combo)
{
	return gtk_combo_box_text_get_active_text(combo);
}

GtkWidget*	get_tree_view_column(int c, GtkTreeView *tree_view)
{
	return gtk_tree_view_get_column(tree_view, c);
}

GtkWidget*	get_file_dialog(GtkFileChooserDialog *dialog)
{
	return gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER_DIALOG(dialog));
}
/*
GdkColor	get_color(GtkColorButton *color_button)
{
	return gtk_color_button_get_color(color_button);
}
*/
PangoFontDescription*	get_font_description(GtkFontButton *font_button)
{
	return gtk_font_button_get_font_name(font_button);
}

gdouble	get_spin_value(GtkSpinButton *spin)
{
	return gtk_spin_button_get_value(spin);
}

/*void	get_scrolled_window(GtkScrolledWindow *scrolled_window, GtkAdjustment **hadjustment, GtkAdjustment **vadjustment)
{
	return gtk_scrolled_window_get_vadjustment(scrolled_window, hadjustment, vadjustment);
}
*/
GtkWidget*	get_paned(GtkWidget *paned)	
{
	return gtk_paned_get_child1(GTK_PANED(paned));
}

GtkWidget*	get_dialog(GtkDialog *dialog)
{
	return gtk_dialog_get_widget_for_response(dialog, GTK_RESPONSE_OK);
}

GtkWidget*	get_container(GtkContainer *container)
{
	return gtk_bin_get_child(GTK_BIN(container));
}
