const char BUILDXML_STR[] = 
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<project name=\"%s\" default=\"help\">\n"
"\n"
"    <!-- The local.properties file is created and updated by the 'android' tool.\n"
"         It contains the path to the SDK. It should *NOT* be checked into\n"
"         Version Control Systems. -->\n"
"    <property file=\"local.properties\" />\n"
"    <property environment=\"env\"/>\n"
"    <property name=\"sdk.dir\" location=\"/${env.ANDROID_SDK}\" /> <!-- sdk.dir is a property, so it won't be overwritten if local.properties already defines it -->    \n"
"    <!-- quick check on sdk.dir -->\n"
"    <fail\n"
"            message=\"sdk.dir is missing. Make sure to generate local.properties using 'android update project' or to inject it through an ANDROID_SDK env var\"\n"
"            unless=\"sdk.dir\"\n"
"    />\n"
"    \n"
"    <!-- The ant.properties file can be created by you. It is only edited by the\n"
"         'android' tool to add properties to it.\n"
"         This is the place to change some Ant specific build properties.\n"
"         Here are some properties you may want to change/update:\n"
"\n"
"         source.dir\n"
"             The name of the source directory. Default is 'src'.\n"
"         out.dir\n"
"             The name of the output directory. Default is 'bin'.\n"
"\n"
"         For other overridable properties, look at the beginning of the rules\n"
"         files in the SDK, at tools/ant/build.xml\n"
"\n"
"         Properties related to the SDK location or the project target should\n"
"         be updated using the 'android' tool with the 'update' action.\n"
"\n"
"         This file is an integral part of the build system for your\n"
"         application and should be checked into Version Control Systems.\n"
"\n"
"         -->\n"
"    <property file=\"ant.properties\" />\n"
"\n"
"    <!-- The project.properties file is created and updated by the 'android'\n"
"         tool, as well as ADT.\n"
"\n"
"         This contains project specific properties such as project target, and library\n"
"         dependencies. Lower level build properties are stored in ant.properties\n"
"         (or in .classpath for Eclipse projects).\n"
"\n"
"         This file is an integral part of the build system for your\n"
"         application and should be checked into Version Control Systems. -->\n"
"    <loadproperties srcFile=\"project.properties\" />\n"
"\n"
"\n"
"\n"
"\n"
"<!-- extension targets. Uncomment the ones where you want to do custom work\n"
"     in between standard targets -->\n"
"<!--\n"
"    <target name=\"-pre-build\">\n"
"    </target>\n"
"    <target name=\"-pre-compile\">\n"
"    </target>\n"
"\n"
"    /* This is typically used for code obfuscation.\n"
"       Compiled code location: ${out.classes.absolute.dir}\n"
"       If this is not done in place, override ${out.dex.input.absolute.dir} */\n"
"    <target name=\"-post-compile\">\n"
"    </target>\n"
"-->\n"
"    <path id=\"android.antlibs\">\n"
"        <pathelement path=\"${sdk.dir}/tools/lib/anttasks.jar\" />\n"
"        <pathelement path=\"${sdk.dir}/tools/lib/sdklib.jar\" />\n"
"        <pathelement path=\"${sdk.dir}/tools/lib/androidprefs.jar\" />\n"
"    </path>\n"
"\n"
"    <target name=\"-pre-build\">\n"
"        <echo>Copying assets</echo>\n"
"        <copy todir=\"${asset.absolute.dir}\">\n"
"	    <fileset dir=\"${asset.absolute.dir}/../../../../application/res\">\n"
"                <include name=\"**/*.txt\"/>\n"
"                <include name=\"**/*.par\"/>\n"
"                <include name=\"**/*.ini\"/>\n"
"            </fileset>\n"
"        </copy>\n"
"	<!--\n"
"        <echo>Copying prebuilt Spitfire Java classes</echo>\n"
"        <unzip src=\"${engine.dir}/configs/platforms/android/engine.jar\" dest=\"${out.dir}/classes\" />\n"
"	-->\n"
"    </target>\n"
"      \n"
"    <target name=\"-package-resources\" depends=\"-crunch\">\n"
"        <echo>Packaging resources</echo>\n"
"        <do-only-if-not-library elseText=\"Library project: do not package resources...\" >\n"
"            <aapt executable=\"${aapt}\"\n"
"                    command=\"package\"\n"
"                    verbose=\"true\"\n"
"                    versioncode=\"${version.code}\"\n"
"                    versionname=\"${version.name}\"\n"
"                    debug=\"${build.is.packaging.debug}\"\n"
"                    manifest=\"AndroidManifest.xml\"\n"
"                    assets=\"${asset.absolute.dir}\"\n"
"                    androidjar=\"${project.target.android.jar}\"\n"
"                    apkfolder=\"${out.absolute.dir}\"\n"
"                    nocrunch=\"${build.packaging.nocrunch}\"\n"
"                    resourcefilename=\"${resource.package.file.name}\"\n"
"                    resourcefilter=\"${aapt.resource.filter}\"\n"
"                    libraryResFolderPathRefid=\"project.libraries.res\"\n"
"                    libraryPackagesRefid=\"project.libraries.package\"\n"
"					libraryRFileRefid=\"project.library.bin.r.file.path\"\n"
"                    previousBuildType=\"${build.last.target}\"\n"
"                    buildType=\"${build.target}\">\n"
"                <res path=\"${out.res.absolute.dir}\" />\n"
"                <res path=\"${resource.absolute.dir}\" />\n"
"                <nocompress extension=\"kzb\" />\n"
"            </aapt>\n"
"        </do-only-if-not-library>\n"
"    </target>\n"
"          \n"
"    <!-- Import the actual build file.\n"
"\n"
"         To customize existing targets, there are two options:\n"
"         - Customize only one target:\n"
"             - copy/paste the target into this file, *before* the\n"
"               <import> task.\n"
"             - customize it to your needs.\n"
"         - Customize the whole content of build.xml\n"
"             - copy/paste the content of the rules files (minus the top node)\n"
"               into this file, replacing the <import> task.\n"
"             - customize to your needs.\n"
"\n"
"         ***********************\n"
"         ****** IMPORTANT ******\n"
"         ***********************\n"
"         In all cases you must update the value of version-tag below to read 'custom' instead of an integer,\n"
"         in order to avoid having your file be overridden by tools such as \"android update project\"\n"
"    -->\n"
"    <!-- version-tag: custom -->\n"
"    <import file=\"${sdk.dir}/tools/ant/build.xml\" />\n"
"    \n"
"</project>\n"
;