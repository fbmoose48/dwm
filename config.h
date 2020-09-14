/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 2;        /* vertical padding for statusbar */
static const char *fonts[]          = {"SauceCodePro Nerd Font:size=12:antialias=true:autohint=true",
					"Hack:size=12:antialias=true:autohint=true",
					"JoyPixels:size=14:antialias=true:autohint=true"
					}; /* monospace:size=10 */
static const char dmenufont[]       = "SauceCodePro Nerd Font:size=12";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444"; /* border color unfocused windows */
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577"; /* border color focused window and tabs */
static const char col_urgborder[]   = "#ff0000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeUrg]  = { col_gray4, col_cyan,  col_urgborder  },
};

/* tagging */
/*static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
/*static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; */
static const char *tags[] = { "", "", "", "", "", "爵" };

/* Launcher (feature disabled in dwm.c) */
/* launcher commands (They must be NULL terminated) */
/*static const char* firefox[]      = { "firefox", NULL };
static const char* chromium[]      = { "chromium", NULL };
static const char* thunderbird[]      = { "thunderbird", NULL };
static const char* nautilus[]      = { "nautilus", NULL };
static const char* network[]      = { "nm-connection-editor", NULL };
static const char* htop[]      = { "st", "-e", "htop", NULL };
static const char* xmrstak[]      = { "st", "-e", "sudo", "/opt/xmr-stak-1.0.5/build/bin/start.sh", NULL };
static const char* config[]      = { "st", "-e", "nano", "/home/brian/dwm/config.h", NULL }; */

/* launcher buttons */
/*static const Launcher launchers[] = { */
       /* command       name to display */
/*	{ firefox,         "" },
	{ chromium,         "" },
	{ thunderbird,         "" },
	{ nautilus,         "" },
	{ network,         "爵" },
	{ htop,         "" },
	{ xmrstak,         "" },
	{ config,         "漣" },
}; */

/* windowing exceptions */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 * -1 = left, 0 = center, 1 = right  */
	/* class		instance	title	tags mask	isfloating	monitor */
	{ "Gimp",		NULL,		NULL,	0,		1,		-1 },
/*	{ "Evince",		NULL,		NULL,	0,		1,		-1 }, */
/*	{ "Navigator",		NULL,		NULL,	1 << 1,		0,		1 }, */
	{ "Thunderbird",	NULL,		NULL,	1 << 4,		0,		0 },
	{ "vlc",		NULL,		NULL,	1 << 3,		0,		0 },
/*	{ "Chromium",		NULL,		NULL,	1 << 5,		0,		0 }, */
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "grid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "HHH",      grid },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "terminator", NULL };
static const char *traycmd[] = { "stalonetray", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *emailcmd[]  = { "thunderbird", NULL };
static const char *filecmd[] = { "nautilus", NULL };
static const char *htopcmd[] = { "st", "-e", "htop", NULL };
static const char *lockcmd[] = { "slock", NULL };
static const char *configcmd[] = { "st", "-e", "nano", "/home/brian/dwm/config.def.h", NULL };
static const char *killcmd[] = { "st", "-e", "sudo", "shutdown", "-h", "now", NULL };
static const char *xmrstakcmd[] = { "st", "-e", "sudo", "/opt/xmr-stak-1.0.5/build/bin/start.sh", NULL };
static const char *vpncmd[] = { "st", "-e", "sudo", "/home/brian/.expressvpnconf/script/dc-vpn.sh", NULL };
static const char *chromecmd[] = { "chromium", NULL };

static Key keys[] = {
	/* modifier                     key		function	argument */
	/* Spawn Windows */
	{ MODKEY,                       XK_p,		spawn,		{.v = dmenucmd } },
	{ MODKEY|ShiftMask,       	XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY,                       XK_q,		spawn,		{.v = traycmd } },
	{ MODKEY,                       XK_w,		spawn,		{.v = browsercmd } },
	{ MODKEY,                       XK_e,		spawn,		{.v = emailcmd } },
	{ MODKEY,                       XK_r,		spawn,		{.v = filecmd } },
	{ MODKEY,                       XK_a,		spawn,		{.v = htopcmd } },
	{ MODKEY,                       XK_s,		spawn,		{.v = lockcmd } },
	{ MODKEY,			XK_d,		spawn,		{.v = chromecmd } },
	{ MODKEY,                       XK_z,		spawn,		{.v = killcmd } },
	{ MODKEY,                       XK_x,		spawn,		{.v = xmrstakcmd } },
	{ MODKEY,			XK_c,		spawn,		{.v = configcmd } },
	{ MODKEY,			XK_v,		spawn,		{.v = vpncmd } },
	/* Stack Manipulation */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	/* Layout Manipulation */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,		XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	/* Monitor Manipulation */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = -1 } },
	/* Tag Manipulation */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
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
};

