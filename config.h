/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 15;       /* snap pixel */
static const unsigned int gappih    = 5;	      /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;        /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
/* normal colors */
static const char *fonts[]          = { "monospace:size=12", "fontawesome:size=16" };
static const char col_gray1[]       = "#222222";	//BG Color
static const char col_gray2[]       = "#444444";	//Standby Border Color
static const char col_gray3[]       = "#bbbbbb";	//Font Color
static const char col_gray4[]       = "#eeeeee";	//Selected Tag & Window Color
static const char col_cyan[]        = "#005577";	//Top Bar and Window Color
/* custom colors */
static const char col_turquoise[]   = "#00FFCF";
static const char col_purple[]      = "#6E35B1";
static const char col_neonpink[]    = "#FF00C9";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_turquoise, col_purple, col_turquoise },
	[SchemeSel]  = { col_purple, col_turquoise,  col_neonpink  },
};
	/* referrence       fg         bg       border
      	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
      	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	*/

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd0[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"keepassxc",   spcmd0},
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",				NULL,				NULL,				0,						1,					 -1 },
	{ "Steam",			NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Claws-mail",	NULL,       NULL,       1 << 3,       0,           -1 },
	{ NULL,					"kdenlive", NULL,       1 << 4,       0,           -1 },
	{ NULL,					"tenacity", NULL,       1 << 4,       0,           -1 },
	{ NULL,					"keepassxc",NULL,				SPTAG(0),			1,					 -1 },
};

/* window swallowing */
static const int swaldecay = 3;
static const int swalretroactive = 1;
static const char swalsymbol[] = "";

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "#=",      tile },    /* first entry is default */
	{ "(O)",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", NULL};
static const char *termcmd[]  = { "alacritty", NULL };
static const char *lfcmd[]  = { "alacritty", "-e", "/usr/bin/lfub", NULL };
static const char *webcmd[]  = { "librewolf", NULL };


static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,												XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,												XK_f,			 spawn,          {.v = lfcmd } },
	{ MODKEY,												XK_w,			 spawn,          {.v = webcmd } },
	{ MODKEY,												XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,							XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ControlMask,						XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,						XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,						XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	/*Gaps*/
	{ MODKEY,          							XK_minus,  togglegaps,     {0} },
	{ MODKEY|ShiftMask,							XK_minus,  defaultgaps,    {0} },
	{ MODKEY,												XK_plus,   incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,							XK_plus,   incrgaps,       {.i = +1 } },
	/*Swallower*/
	{ MODKEY,                       XK_u,      swalstopsel,    {0} },
	/*ScratchPads*/
	{ MODKEY|ShiftMask,							XK_o,			 togglescratch,  {.ui = 0 } },
	/*Stacker*/
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Escape, quit,        {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	/*Swallower*/
	{ ClkClientWin,         MODKEY|ShiftMask, Button1,      swalmouse,      {0} },
};

