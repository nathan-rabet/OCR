# include <gtk/gtk.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <ctype.h>

GtkWidget *window;
GtkWidget *binarization;
GtkWidget *Read_text;
GtkWidget *Save;
GtkWidget *OCR;
GtkWidget *img_input;
GtkWidget *network_input;
GtkWidget *save_name;
GtkWidget *image;
GtkWidget *text;
GtkWidget *no_img;
GtkWidget *no_txt;
GtkBuilder *builder;

char img_path[];
char save_folder_path[];
char txt[];
char save_file_name[128];

// Main function.
int main () {
        // Initializes GTK.
        gtk_init(NULL, NULL);

	builder = gtk_builder_new_from_file ("OCR_interface.glade");
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	binarization = GTK_WIDGET(gtk_builder_get_object(builder, "binarization"));
	Read_text = GTK_WIDGET(gtk_builder_get_object(builder, "Read_text"));
	Save = GTK_WIDGET(gtk_builder_get_object(builder, "Save"));
	OCR = GTK_WIDGET(gtk_builder_get_object(builder, "OCR"));
	img_input = GTK_WIDGET(gtk_builder_get_object(builder, "img_input"));
	network_input = GTK_WIDGET(gtk_builder_get_object(builder, "network_input"));
	save_name = GTK_WIDGET(gtk_builder_get_object(builder, "save_name"));
	image = GTK_WIDGET(gtk_builder_get_object(builder, "image"));
	text = GTK_WIDGET(gtk_builder_get_object(builder, "text"));
	no_img = GTK_WIDGET(gtk_builder_get_object(builder, "no_img"));
	no_txt = GTK_WIDGET(gtk_builder_get_object(builder, "no_txt"));

	gtk_widget_show(window);


	gtk_main();
	
	return EXIT_SUCCESS;
}

void on_binarization_clicked (GtkButton *b) {
	//file = binarization(file)
	//On ferme précèdente fenetre avec img si non déjà fermé
	//fc SDL pour print img binarisé et segmenté dans une autre fenetre
	gtk_label_set_text(GTK_LABEL(no_txt), (const gchar*) "");
}

void on_Read_text_clicked (GtkButton *b) {
	//prend le fichier avec image segmenté et input son txt dans la zone
	txt[50] = "help";
}	

void on_Save_clicked (GtkButton *b) { //sauvegarde txt 
	FILE *save = fopen(strcat(save_folder_path, save_file_name), "w");
	fprintf(save, "%s", txt);   //A COMPLETER
	fclose(save);
}

void on_img_input_file_set(GtkFileChooserButton *f) {
	printf("file name = %s\n",gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(f)));
	//fc SDL pour print img dans une autre fenetre
	gtk_label_set_text(GTK_LABEL(no_img), (const gchar*) "");
}

void on_network_input_file_set(GtkFileChooserButton *f) {
	printf("[filechooser] got the file %s", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(f)));
}

void on_save_name_changed(GtkEntry *e) {
	char save_file_name[128];
	sprintf(save_file_name, "entry=\s\n", gtk_entry_get_text(e));
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
