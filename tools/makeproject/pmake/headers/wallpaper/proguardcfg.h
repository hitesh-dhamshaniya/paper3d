const char PROGUARDCFG_STR[] = 
"# This is a configuration file for ProGuard.\n"
"# http://proguard.sourceforge.net/index.html#manual/usage.html\n"
"\n"
"-dontusemixedcaseclassnames\n"
"-dontskipnonpubliclibraryclasses\n"
"-verbose\n"
"-ignorewarnings\n"
"\n"
"# Optimization is turned off by default. Dex does not like code run\n"
"# through the ProGuard optimize and preverify steps (and performs some\n"
"# of these optimizations on its own).\n"
"-dontoptimize\n"
"-dontpreverify\n"
"\n"
"# If you want to enable optimization, you should include the\n"
"# following:\n"
"# -optimizations !code/simplification/arithmetic,!code/simplification/cast,!field/*,!class/merging/*\n"
"# -optimizationpasses 5\n"
"# -allowaccessmodification\n"
"#\n"
"# Note that you cannot just include these flags in your own\n"
"# configuration file; if you are including this file, optimization\n"
"# will be turned off. You'll need to either edit this file, or\n"
"# duplicate the contents of this file and remove the include of this\n"
"# file from your project's proguard.config path property.\n"
"\n"
"-keepattributes *Annotation*\n"
"-keep public class * extends android.app.Activity\n"
"-keep public class * extends android.app.Application\n"
"-keep public class * extends android.app.Service\n"
"-keep public class * extends WallpaperService.Engine\n"
"-keep public class * extends android.content.BroadcastReceiver\n"
"-keep public class * extends android.content.ContentProvider\n"
"-keep public class * extends android.app.backup.BackupAgent\n"
"-keep public class * extends android.preference.Preference\n"
"-keep public class * extends android.support.v4.app.Fragment\n"
"-keep public class * extends android.app.Fragment\n"
"-keep public class com.android.vending.licensing.ILicensingService\n"
"\n"
"\n"
"# For native methods, see http://proguard.sourceforge.net/manual/examples.html#native\n"
"-keepclasseswithmembernames class * {\n"
"    native <methods>;\n"
"}\n"
"\n"
"-keep public class * extends android.view.View {\n"
"    public <init>(android.content.Context);\n"
"    public <init>(android.content.Context, android.util.AttributeSet);\n"
"    public <init>(android.content.Context, android.util.AttributeSet, int);\n"
"    public void set*(...);\n"
"}\n"
"\n"
"-keepclasseswithmembers class * {\n"
"    public <init>(android.content.Context, android.util.AttributeSet);\n"
"}\n"
"\n"
"-keepclasseswithmembers class * {\n"
"    public <init>(android.content.Context, android.util.AttributeSet, int);\n"
"}\n"
"\n"
"-keepclassmembers class * extends android.app.Activity {\n"
"   public void *(android.view.View);\n"
"}\n"
"\n"
"# For enumeration classes, see http://proguard.sourceforge.net/manual/examples.html#enumerations\n"
"-keepclassmembers enum * {\n"
"    public static **[] values();\n"
"    public static ** valueOf(java.lang.String);\n"
"}\n"
"\n"
"-keep class * implements android.os.Parcelable {\n"
"  public static final android.os.Parcelable$Creator *;\n"
"}\n"
"\n"
"-keepclassmembers class **.R$* {\n"
"    public static <fields>;\n"
"}\n"
"\n"
"# The support library contains references to newer platform versions.\n"
"# Don't warn about those in case this app is linking against an older\n"
"# platform version.  We know about them, and they are safe.\n"
"-dontwarn android.support.**\n"
"\n"
"# umeng\n"
"-keep class com.umeng.** \n"
;