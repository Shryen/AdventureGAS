

#include "UI/Widgets/AdventureUserWidget.h"

void UAdventureUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
