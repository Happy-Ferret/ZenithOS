if (!FileFind("~/TimeClock",,FUF_JUST_DIRS)) {
	DirMake("~/TimeClock");
	DocClear;
	"After Loading, type $$GREEN$$PunchIn;$$FG$$, "
	"$$GREEN$$PunchOut;$$FG$$ or $$GREEN$$TimeRep;$$FG$$\n"
	"You might want to make PLUGINS for hot keys.\n\n\n";
}

