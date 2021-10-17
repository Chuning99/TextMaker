cmake_minimum_required(VERSION 3.17)
project(project1SFMLType)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1SFMLType main.cpp TextInput.cpp TextInput.h EventHandler.cpp EventHandler.h States.cpp States.h Snapshot.cpp Snapshot.h GUIComponent.cpp GUIComponent.h KeyboardShortcuts.cpp KeyboardShortcuts.h MouseEvents.h History.h Animate.cpp Animate.h SnapshotInterface.h node.h Iterator.h Stack.h linkedlist.h Constant.h Cursor.cpp Cursor.h Inputbox.cpp Inputbox.h TextLabel.cpp TextLabel.h Item.cpp Item.h ItemList.cpp ItemList.h DropdownMenu.cpp DropdownMenu.h Menu.cpp Menu.h MenuBar.cpp MenuBar.h Image.h FileItem.cpp FileItem.h FileNode.cpp FileNode.h FileTree.cpp FileTree.h Image.cpp Fonts.cpp Fonts.h ShadowText.cpp ShadowText.h Slider.cpp Slider.h HSVPicker.cpp HSVPicker.h SliderBar.cpp SliderBar.h Palette.cpp Palette.h Color.cpp Color.h ColorPicker.cpp ColorPicker.h Button.cpp Button.h)

target_link_libraries(project1SFMLType sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)