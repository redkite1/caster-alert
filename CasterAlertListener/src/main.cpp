#include <QApplication>
#include "casteralertlistenerimpl.h"

int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
        CasterAlertListenerImpl win;

	win.show(); 
        app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

	return app.exec();
}
