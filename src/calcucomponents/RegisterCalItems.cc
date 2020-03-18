#include "RegisterCalItems.h"
#include "ICalItemRegistrar.h"
#include "OneGlassPanel.h"
#include "GLogHelper.h"

void RegisterCalItems:: RegiterGlassItems()
{
	LOG(INFO)<<"registerGlassItems";
	static	CalItemRegistrar<CalculateItem,OneGlassPanel>oneGlassPanel(GlassParameters::GlassTypeStrs[GlassParameters::ONE]);
}
void RegisterCalItems::RegiterAllItems()
{
	LOG(INFO)<<"registerCalItems";
	RegiterGlassItems();
}



