#include "RegisterCalItems.h"
#include "ICalItemRegistrar.h"
#include "OneGlassPanel.h"
#include "GLogHelper.h"

void RegisterCalItems:: RegiterGlassItems()
{

	LOG(INFO)<<"registerItems";
	static	CalItemRegistrar<CalculateItem,OneGlassPanel>oneGlassPanel(GlassParameters::GlassTypeStrs[GlassParameters::ONE]);
}
void RegisterCalItems::RegiterAllItems()
{
	RegiterGlassItems();
}



