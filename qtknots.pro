# Add more folders to ship with the application, here
folder_01.source = ./res
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve Qml modules in Creator's code model
QML_IMPORT_PATH =

# Avoid auto screen rotation
#DEFINES += ORIENTATIONLOCK

# Needs to be defined for Symbian
#DEFINES += NETWORKACCESS

symbian:TARGET.UID3 = 0xEB530529

# Define QMLJSDEBUGGER to allow debugging of QML
# (This might significantly increase build time)
#DEFINES += QMLJSDEBUGGER


CONFIG      += link_pkgconfig
PKGCONFIG   += glib-2.0 dbus-1 libosso

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    knots.cpp \
    profile.cpp \
    saxprofilehandler.cpp \
    knotsdeclarative.cpp \
    mainwindow.cpp \
    knotsplayerproperties.cpp \
    knotsplayer.cpp \
    knotsitem.cpp \
    knotsdirectory.cpp \
    saxknotsitemhandler.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

include(models/models.pri)
include(kernel/kernel.pri)

HEADERS += \
    knots.h \
    profile.h \
    saxprofilehandler.h \
    knotsdeclarative.h \
    mainwindow.h \
    knotsplayerproperties.h \
    knotsplayer.h \
    knotsitem.h \
    knotsdirectory.h \
    saxknotsitemhandler.h

QT           += xml network opengl

maemo5 {
    QT += dbus
}

RESOURCES += \
    qtknots.qrc

OTHER_FILES += \
    qml/QKnots.qml \
    qml/common/VideoControls.qml \
    qml/common/ToolBar.qml \
    qml/common/Slider.qml \
    qml/common/SearchView.qml \
    qml/common/Progress.qml \
    qml/common/ProfilesView.qml \
    qml/common/ProfilesDelegate.qml \
    qml/common/PlayingView.qml \
    qml/common/OptionsView.qml \
    qml/common/OptionsPage.qml \
    qml/common/OptionsModel.qml \
    qml/common/GridDelegate.qml \
    qml/common/DirectoryDelegate.qml \
    qml/common/Button.qml \
    qml/images/tooltip-background.png \
    qml/images/toolbutton.sci \
    qml/images/toolbutton.png \
    qml/images/toolbar-button-hover.png \
    qml/images/toggle-handle.png \
    qml/images/toggle-background-active.png \
    qml/images/toggle-background.png \
    qml/images/titlebar.sci \
    qml/images/titlebar.png \
    qml/images/stripes.png \
    qml/images/slider-handle-hover.png \
    qml/images/slider-handle-focus.png \
    qml/images/slider-handle-disabled.png \
    qml/images/slider-handle-active.png \
    qml/images/slider-handle.png \
    qml/images/slider-background-hover.png \
    qml/images/slider-background-focus.png \
    qml/images/slider-background-disabled.png \
    qml/images/slider-background-active.png \
    qml/images/slider-background.png \
    qml/images/scroll-vhandle-hover.png \
    qml/images/scroll-vhandle-disabled.png \
    qml/images/scroll-vhandle-active.png \
    qml/images/scroll-vhandle.png \
    qml/images/scroll-vbackground-disabled.png \
    qml/images/scroll-vbackground.png \
    qml/images/scroll-hhandle-hover.png \
    qml/images/scroll-hhandle-disabled.png \
    qml/images/scroll-hhandle-active.png \
    qml/images/scroll-hhandle.png \
    qml/images/scroll-hbackground-disabled.png \
    qml/images/scroll-hbackground.png \
    qml/images/scroll-button-up-hover.png \
    qml/images/scroll-button-up.png \
    qml/images/scroll-button-right-hover.png \
    qml/images/scroll-button-right.png \
    qml/images/scroll-button-left-hover.png \
    qml/images/scroll-button-left.png \
    qml/images/scroll-button-down-hover.png \
    qml/images/scroll-button-down.png \
    qml/images/resize-grip.png \
    qml/images/quit.png \
    qml/images/progress-bar-bar.png \
    qml/images/progress-bar-background.png \
    qml/images/plus-button-hover.png \
    qml/images/plus-button-checked-hover.png \
    qml/images/plus-button-checked.png \
    qml/images/plus-button.png \
    qml/images/pathbar-button-last-hover.png \
    qml/images/pathbar-button-last-focus.png \
    qml/images/pathbar-button-last-active.png \
    qml/images/pathbar-button-last.png \
    qml/images/pathbar-button-hover.png \
    qml/images/pathbar-button-focus.png \
    qml/images/pathbar-button-active.png \
    qml/images/pathbar-button.png \
    qml/images/menu-toolbar.png \
    qml/images/menu-item.png \
    qml/images/menu.png \
    qml/images/Makefile.am \
    qml/images/lineedit.sci \
    qml/images/lineedit.png \
    qml/images/knots2.png \
    qml/images/knots_item_video.png \
    qml/images/knots_item_server.png \
    qml/images/knots_item_music.png \
    qml/images/knots_item_connect.png \
    qml/images/knots_dir.png \
    qml/images/knots_button_stop.png \
    qml/images/knots_button_search.png \
    qml/images/knots_button_save_as.png \
    qml/images/knots_button_repeat.png \
    qml/images/knots_button_reorder.png \
    qml/images/knots_button_remove_from_playlist.png \
    qml/images/knots_button_rate.png \
    qml/images/knots_button_prev.png \
    qml/images/knots_button_playlist.png \
    qml/images/knots_button_player.png \
    qml/images/knots_button_play_artist.png \
    qml/images/knots_button_play_album.png \
    qml/images/knots_button_play.png \
    qml/images/knots_button_no_repeat.png \
    qml/images/knots_button_next_item.png \
    qml/images/knots_button_next.png \
    qml/images/knots_button_new.png \
    qml/images/knots_button_lyrics.png \
    qml/images/knots_button_info.png \
    qml/images/knots_button_delete.png \
    qml/images/knots_button_clear_position.png \
    qml/images/knots_button_back.png \
    qml/images/knots_button_add_to_playlist.png \
    qml/images/gloss.png \
    qml/images/expander-open.png \
    qml/images/expander-hover.png \
    qml/images/expander-closed.png \
    qml/images/expander-arrow-up-hover.png \
    qml/images/expander-arrow-up.png \
    qml/images/expander-arrow-down-hover.png \
    qml/images/expander-arrow-down.png \
    qml/images/entry-active.png \
    qml/images/entry.png \
    qml/images/edit-find.png \
    qml/images/edit-clear.png \
    qml/images/default.css \
    qml/images/combobox-toolbar-marker.png \
    qml/images/combobox-toolbar.png \
    qml/images/combobox-marker.png \
    qml/images/combobox.png \
    qml/images/close-hover.png \
    qml/images/close.png \
    qml/images/button-hover.png \
    qml/images/button-active.png \
    qml/images/button.png \
    qml/images/.directory \
    qml/images/wmTaskSwitcherIconPressed.png \
    qml/images/wmTaskSwitcherIcon.png \
    qml/images/wmCloseIconPressed.png \
    qml/images/wmCloseIcon.png \
    qml/images/tooltip-background.png \
    qml/images/toolbutton.sci \
    qml/images/toolbutton.png \
    qml/images/toolbar-button-hover.png \
    qml/images/toggle-handle.png \
    qml/images/toggle-background-active.png \
    qml/images/toggle-background.png \
    qml/images/titlebar.sci \
    qml/images/titlebar.png \
    qml/images/stripes.png \
    qml/images/slider-handle-hover.png \
    qml/images/slider-handle-focus.png \
    qml/images/slider-handle-disabled.png \
    qml/images/slider-handle-active.png \
    qml/images/slider-handle.png \
    qml/images/slider-background-hover.png \
    qml/images/slider-background-focus.png \
    qml/images/slider-background-disabled.png \
    qml/images/slider-background-active.png \
    qml/images/slider-background.png \
    qml/images/scroll-vhandle-hover.png \
    qml/images/scroll-vhandle-disabled.png \
    qml/images/scroll-vhandle-active.png \
    qml/images/scroll-vhandle.png \
    qml/images/scroll-vbackground-disabled.png \
    qml/images/scroll-vbackground.png \
    qml/images/scroll-hhandle-hover.png \
    qml/images/scroll-hhandle-disabled.png \
    qml/images/scroll-hhandle-active.png \
    qml/images/scroll-hhandle.png \
    qml/images/scroll-hbackground-disabled.png \
    qml/images/scroll-hbackground.png \
    qml/images/scroll-button-up-hover.png \
    qml/images/scroll-button-up.png \
    qml/images/scroll-button-right-hover.png \
    qml/images/scroll-button-right.png \
    qml/images/scroll-button-left-hover.png \
    qml/images/scroll-button-left.png \
    qml/images/scroll-button-down-hover.png \
    qml/images/scroll-button-down.png \
    qml/images/resize-grip.png \
    qml/images/quit.png \
    qml/images/progress-bar-bar.png \
    qml/images/progress-bar-background.png \
    qml/images/plus-button-hover.png \
    qml/images/plus-button-checked-hover.png \
    qml/images/plus-button-checked.png \
    qml/images/plus-button.png \
    qml/images/pathbar-button-last-hover.png \
    qml/images/pathbar-button-last-focus.png \
    qml/images/pathbar-button-last-active.png \
    qml/images/pathbar-button-last.png \
    qml/images/pathbar-button-hover.png \
    qml/images/pathbar-button-focus.png \
    qml/images/pathbar-button-active.png \
    qml/images/pathbar-button.png \
    qml/images/menu-toolbar.png \
    qml/images/menu-item.png \
    qml/images/menu.png \
    qml/images/Makefile.am \
    qml/images/lineedit.sci \
    qml/images/lineedit.png \
    qml/images/knots2.png \
    qml/images/knots_item_video.png \
    qml/images/knots_item_server.png \
    qml/images/knots_item_music.png \
    qml/images/knots_item_connect.png \
    qml/images/knots_dir.png \
    qml/images/knots_button_stop.png \
    qml/images/knots_button_search.png \
    qml/images/knots_button_save_as.png \
    qml/images/knots_button_repeat.png \
    qml/images/knots_button_reorder.png \
    qml/images/knots_button_remove_from_playlist.png \
    qml/images/knots_button_rate.png \
    qml/images/knots_button_prev.png \
    qml/images/knots_button_playlist.png \
    qml/images/knots_button_player.png \
    qml/images/knots_button_play_artist.png \
    qml/images/knots_button_play_album.png \
    qml/images/knots_button_play.png \
    qml/images/knots_button_no_repeat.png \
    qml/images/knots_button_next_item.png \
    qml/images/knots_button_next.png \
    qml/images/knots_button_new.png \
    qml/images/knots_button_lyrics.png \
    qml/images/knots_button_info.png \
    qml/images/knots_button_delete.png \
    qml/images/knots_button_clear_position.png \
    qml/images/knots_button_back.png \
    qml/images/knots_button_add_to_playlist.png \
    qml/images/gloss.png \
    qml/images/expander-open.png \
    qml/images/expander-hover.png \
    qml/images/expander-closed.png \
    qml/images/expander-arrow-up-hover.png \
    qml/images/expander-arrow-up.png \
    qml/images/expander-arrow-down-hover.png \
    qml/images/expander-arrow-down.png \
    qml/images/entry-active.png \
    qml/images/entry.png \
    qml/images/edit-find.png \
    qml/images/edit-clear.png \
    qml/images/default.css \
    qml/images/combobox-toolbar-marker.png \
    qml/images/combobox-toolbar.png \
    qml/images/combobox-marker.png \
    qml/images/combobox.png \
    qml/images/close-hover.png \
    qml/images/close.png \
    qml/images/button-hover.png \
    qml/images/button-active.png \
    qml/images/button.png \
    qml/images/.directory \
    qml/images/mediaplayer/VideoOverlayButtonPressed.png \
    qml/images/mediaplayer/VideoOverlayButton.png \
    qml/images/mediaplayer/StopPressed.png \
    qml/images/mediaplayer/Stop.png \
    qml/images/mediaplayer/ShufflePressed.png \
    qml/images/mediaplayer/Shuffle.png \
    qml/images/mediaplayer/RepeatPressed.png \
    qml/images/mediaplayer/Repeat.png \
    qml/images/mediaplayer/Play.png \
    qml/images/mediaplayer/Pause.png \
    qml/images/mediaplayer/ForwardPressed.png \
    qml/images/mediaplayer/Forward.png \
    qml/images/mediaplayer/CrossfadePressed.png \
    qml/images/mediaplayer/Crossfade.png \
    qml/images/mediaplayer/Button.png \
    qml/images/mediaplayer/BackPressed.png \
    qml/images/mediaplayer/background.png \
    qml/images/mediaplayer/Back.png \
    qml/images/mediaplayer/AppletStop.png \
    qml/images/mediaplayer/AppletPlay.png \
    qml/images/mediaplayer/AppletPause.png \
    qml/images/mediaplayer/AppletForward.png \
    qml/images/mediaplayer/AppletBack.png \
    qml/common/TitleBar.qml
