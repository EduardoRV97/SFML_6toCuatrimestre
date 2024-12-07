#include "GUI.h"

#include "imgui_internal.h"
#include "ShapeFactory.h"
#include "Transform.h"
#include "Actor.h"

class
  ShapeFactory;

/**
 * @brief Inicializa la GUI y configura el estilo.
 */
void
GUI::init() {
  // Configurar estilo de GUI
  setupGUIStyle();

  selectedActorIndex = 0;
}

/**
 * @brief Actualiza la GUI. Este m�todo puede ser extendido para incluir l�gica de actualizaci�n en cada frame.
 */
void
GUI::update() {
}

/**
 * @brief Renderiza la GUI. M�todo utilizado para a�adir l�gica de renderizado.
 */
void
GUI::render() {
}

/**
 * @brief Destruye la GUI y libera los recursos asociados.
 */
void
GUI::destroy() {
}

/**
 * @brief Configura el estilo de la GUI utilizando colores y espaciamiento espec�ficos.
 */
void
GUI::setupGUIStyle() {
  ImGuiStyle& style = ImGui::GetStyle();
  ImVec4* colors = style.Colors;

  // Configuraci�n general de estilo
  style.WindowRounding = 0.0f;
  style.FrameRounding = 0.0f;
  style.PopupRounding = 0.0f;
  style.ScrollbarRounding = 0.0f;
  style.GrabRounding = 0.0f;
  style.TabRounding = 0.0f;
  style.ChildRounding = 0.0f;
  style.FrameBorderSize = 1.0f;
  style.WindowBorderSize = 1.0f;
  style.PopupBorderSize = 1.0f;
  style.TabBorderSize = 1.0f;

  // Definici�n de colores
  ImVec4 white = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
  ImVec4 black = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
  ImVec4 red = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
  ImVec4 blue = ImVec4(0.0f, 0.5f, 1.0f, 1.0f);
  ImVec4 lime = ImVec4(0.5f, 1.0f, 0.0f, 1.0f);
  ImVec4 yellow = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

  // Fondo de la ventana y elementos
  colors[ImGuiCol_WindowBg] = white;
  colors[ImGuiCol_ChildBg] = white;
  colors[ImGuiCol_PopupBg] = white;

  // Texto y bordes
  colors[ImGuiCol_Text] = black;
  colors[ImGuiCol_Border] = black;
  colors[ImGuiCol_BorderShadow] = black;

  // Botones
  colors[ImGuiCol_Button] = red;
  colors[ImGuiCol_ButtonHovered] = blue;
  colors[ImGuiCol_ButtonActive] = lime;

  // Marcos y campos de entrada
  colors[ImGuiCol_FrameBg] = white;
  colors[ImGuiCol_FrameBgHovered] = yellow;
  colors[ImGuiCol_FrameBgActive] = yellow;

  // T�tulos y encabezados
  colors[ImGuiCol_TitleBg] = white;
  colors[ImGuiCol_TitleBgActive] = white;
  colors[ImGuiCol_TitleBgCollapsed] = white;

  colors[ImGuiCol_Header] = red;
  colors[ImGuiCol_HeaderHovered] = blue;
  colors[ImGuiCol_HeaderActive] = lime;

  // Tabs
  colors[ImGuiCol_Tab] = red;
  colors[ImGuiCol_TabHovered] = blue;
  colors[ImGuiCol_TabActive] = lime;
  colors[ImGuiCol_TabUnfocused] = red;
  colors[ImGuiCol_TabUnfocusedActive] = lime;

  // Scrollbar
  colors[ImGuiCol_ScrollbarBg] = white;
  colors[ImGuiCol_ScrollbarGrab] = black;
  colors[ImGuiCol_ScrollbarGrabHovered] = black;
  colors[ImGuiCol_ScrollbarGrabActive] = black;

  // Sliders
  colors[ImGuiCol_SliderGrab] = black;
  colors[ImGuiCol_SliderGrabActive] = black;

  // Checkbox y radio button
  colors[ImGuiCol_CheckMark] = black;

  // Separadores y l�neas
  colors[ImGuiCol_Separator] = black;
  colors[ImGuiCol_SeparatorHovered] = black;
  colors[ImGuiCol_SeparatorActive] = black;

  // Men�
  colors[ImGuiCol_MenuBarBg] = white;

  // Tooltip
  colors[ImGuiCol_TextSelectedBg] = blue;
  colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.2f, 0.2f, 0.2f, 0.5f);

  // Ajustes de alineaci�n y espaciado
  style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
  style.ItemSpacing = ImVec2(8, 4);
  style.ItemInnerSpacing = ImVec2(4, 4);
  style.FramePadding = ImVec2(4, 2);
}

void
GUI::barMenu() {
  if (ImGui::BeginMainMenuBar()) {

    // Men� Archivo
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("New")) {
        // Acci�n para nuevo archivo
      }
      if (ImGui::MenuItem("Open", "Ctrl+O")) {
        // Acci�n para abrir archivo
      }
      if (ImGui::MenuItem("Save", "Ctrl+S")) {
        // Acci�n para guardar archivo
      }
      if (ImGui::MenuItem("Save As..")) {
        // Acci�n para guardar como
      }
      ImGui::Separator();
      if (ImGui::MenuItem("Exit", "Alt+F4")) {
        // Acci�n para salir
        exit(1);
      }
      ImGui::EndMenu();
    }

    // Men� Editar
    if (ImGui::BeginMenu("Edit")) {
      if (ImGui::MenuItem("Undo", "Ctrl+Z")) {
        // Acci�n para deshacer
      }
      if (ImGui::MenuItem("Redo", "Ctrl+Y")) {
        // Acci�n para rehacer
      }
      ImGui::Separator();
      if (ImGui::MenuItem("Cut", "Ctrl+X")) {
        // Acci�n para cortar
      }
      if (ImGui::MenuItem("Copy", "Ctrl+C")) {
        // Acci�n para copiar
      }
      if (ImGui::MenuItem("Paste", "Ctrl+V")) {
        // Acci�n para pegar
      }
      ImGui::EndMenu();
    }

    // Men� Ver
    if (ImGui::BeginMenu("View")) {
      if (ImGui::MenuItem("Show Console")) {
        // Acci�n para mostrar la consola
      }
      if (ImGui::MenuItem("Show Hierarchy")) {
        // Acci�n para mostrar la jerarqu�a
      }
      ImGui::EndMenu();
    }

    // Men� Herramientas
    if (ImGui::BeginMenu("Tools")) {
      if (ImGui::MenuItem("Options")) {
        // Acci�n para mostrar opciones
      }
      ImGui::EndMenu();
    }

    // Men� Ayuda
    if (ImGui::BeginMenu("Help")) {
      if (ImGui::MenuItem("Documentation")) {
        // Acci�n para abrir documentaci�n
      }
      if (ImGui::MenuItem("About")) {
        // Acci�n para mostrar informaci�n sobre el programa
      }
      ImGui::EndMenu();
    }

    ImGui::EndMainMenuBar();
  }
}


/**
 * @brief Muestra una consola con los mensajes del programa.
 * @param programMessages Mapa de mensajes del programa categorizados por tipo de error.
 */
void
GUI::console(const std::map<ConsoleErrorType, std::vector<std::string>>& programMessages) {
  ImGui::Begin("Console");

  static ImGuiTextFilter filter; // Filtro de b�squeda
  filter.Draw("Filter (\"error\", \"warning\", etc.)", 180.0f);

  ImGui::Separator();

  ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

  for (const auto& pair : programMessages) {
    // Establece color seg�n el tipo de mensaje
    ImVec4 color;
    switch (pair.first) {
    case ConsoleErrorType::ERROR:
      color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); // Rojo para errores
      break;
    case ConsoleErrorType::WARNING:
      color = ImVec4(1.0f, 1.0f, 0.4f, 1.0f); // Amarillo para advertencias
      break;
    case ConsoleErrorType::INFO:
    default:
      color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f); // Gris para mensajes de informaci�n
      break;
    }

    for (const auto& message : pair.second) {
      if (!filter.PassFilter(message.c_str())) continue; // Filtrar mensajes seg�n el filtro de b�squeda

      ImGui::PushStyleColor(ImGuiCol_Text, color);
      ImGui::Text("[%d] %s", pair.first, message.c_str());
      ImGui::PopStyleColor();
    }
  }

  // Desplazamiento autom�tico al final
  if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
    ImGui::SetScrollHereY(1.0f);

  ImGui::EndChild();
  ImGui::End();
}

/**
 * @brief Muestra un componente Outliner que permite organizar y seleccionar actores.
 * @param actors Vector de actores a mostrar en el Outliner.
 */
void
GUI::outliner(std::vector<EngineUtilities::TSharedPointer<Actor>> actors) {
  ImGui::Begin("Hierarchy");

  // Barra de b�squeda
  static ImGuiTextFilter filter;
  filter.Draw("Search...", 180.0f); // Barra de b�squeda con ancho ajustable

  ImGui::Separator();

  // Recorrer y mostrar cada actor que pase el filtro de b�squeda
  for (int i = 0; i < actors.size(); ++i) {
    const auto& actor = actors[i];

    // Obtener el nombre del actor o asignar un nombre gen�rico
    std::string actorName = actor ? actor->getName() : "Unnamed Actor";

    // Verificar si el actor pasa el filtro de b�squeda
    if (!filter.PassFilter(actorName.c_str())) {
      continue; // Saltar actores que no coincidan con el filtro
    }

    // Si el actor es seleccionable
    ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;
    if (selectedActorIndex == i)
      flags |= ImGuiTreeNodeFlags_Selected;

    // Crear un nodo de �rbol para cada actor
    bool nodeOpen = ImGui::TreeNodeEx((void*)(intptr_t)i, flags, "%s", actorName.c_str());

    // Selecci�n de actor
    if (ImGui::IsItemClicked()) {
      selectedActorIndex = i;
      // Aqu� puedes llamar a alguna funci�n para mostrar los detalles del actor en otra ventana
    }

    // Mostrar nodos hijos si el nodo est� abierto
    if (nodeOpen) {
      //ImGui::Text("Position: %.2f, %.2f, %.2f", actor->getPosition().x, actor->getPosition().y, actor->getPosition().z);
      ImGui::TreePop();
    }
  }

  ImGui::End();
}

/**
 * @brief Muestra un componente para agregar actores con un tipo de forma espec�fico.
 * @param actors Vector de actores donde se a�adir� el nuevo actor.
 */
void
GUI::placeActors(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
  ImGui::Begin("Place Actors");

  static char actorName[128] = "";
  ImGui::InputText("Name", actorName, IM_ARRAYSIZE(actorName));

  static int shapeType = 0;
  const char* shapeTypes[] = { "NONE", "CIRCLE", "RECTANGLE", "TRIANGLE" };
  ImGui::Combo("Shape Type", &shapeType, shapeTypes, IM_ARRAYSIZE(shapeTypes));

  if (ImGui::Button("Create Actor")) {
    EngineUtilities::TSharedPointer<Actor> newActor = EngineUtilities::MakeShared<Actor>(actorName);

    auto shapeFactory = newActor->getComponent<ShapeFactory>();
    if (shapeFactory) {
      switch (shapeType) {
      case 1:
        shapeFactory->createShape(ShapeType::CIRCLE);
        break;
      case 2:
        shapeFactory->createShape(ShapeType::RECTANGLE);
        break;
      case 3:
        shapeFactory->createShape(ShapeType::TRIANGLE);
        break;
      }
    }
    else {
      ImGui::Text("ShapeFactory component not found.");
    }

    actors.push_back(newActor);
  }

  ImGui::End();
}

/**
 * @brief Muestra el inspector que permite ver y editar las propiedades de los actores y sus componentes.
 * @param actors Vector de actores a mostrar en el inspector.
 */
void
GUI::inspector(std::vector<EngineUtilities::TSharedPointer<Actor>> actors) {
  bool show_demo_window = true;
  ImGui::Begin("Inspector");
  // Checkbox para Static
  bool isStatic = false;
  ImGui::Checkbox("##Static", &isStatic);
  ImGui::SameLine();

  // Input text para el nombre del objeto
  char objectName[128];
  std::string name = actors[selectedActorIndex]->getName();
  std::copy(name.begin(), name.end(), objectName);
  objectName[name.size()] = '\0';  // Asegurarse de terminar la cadena

  //ImGui::SetNextItemWidth(ImGui::GetContentRegionAvailWidth() * 0.6f);
  ImGui::InputText("##ObjectName", objectName, IM_ARRAYSIZE(objectName));
  ImGui::SameLine();

  // Icono (este puede ser una imagen, aqu� solo como ejemplo de bot�n)
  if (ImGui::Button("Icon")) {
    // L�gica del bot�n de icono aqu�
  }

  // Separador horizontal
  ImGui::Separator();

  // Dropdown para Tag
  const char* tags[] = { "Untagged", "Player", "Enemy", "Environment" };
  static int currentTag = 0;
  //ImGui::SetNextItemWidth(ImGui::GetContentRegionAvailWidth() * 0.5f);
  ImGui::Combo("Tag", &currentTag, tags, IM_ARRAYSIZE(tags));
  ImGui::SameLine();

  // Dropdown para Layer
  const char* layers[] = { "Default", "TransparentFX", "Ignore Raycast", "Water", "UI" };
  static int currentLayer = 0;
  //ImGui::SetNextItemWidth(ImGui::GetContentRegionAvailWidth() * 0.5f);
  ImGui::Combo("Layer", &currentLayer, layers, IM_ARRAYSIZE(layers));

  ImGui::Separator();

  // Transform elements
  vec2Control("Position", actors[selectedActorIndex]->getComponent<Transform>()->getPosData());
  vec2Control("Rotation", actors[selectedActorIndex]->getComponent<Transform>()->getRotData());
  vec2Control("Scale", actors[selectedActorIndex]->getComponent<Transform>()->getScaData());

  ImGui::End();
}

void
GUI::vec2Control(const std::string& label, float* values, float resetValue, float columnWidth) {
  ImGuiIO& io = ImGui::GetIO();
  auto boldFont = io.Fonts->Fonts[0];

  ImGui::PushID(label.c_str());

  ImGui::Columns(2);
  ImGui::SetColumnWidth(0, columnWidth);
  ImGui::Text(label.c_str());
  ImGui::NextColumn();

  ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
  ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

  float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
  ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
  ImGui::PushFont(boldFont);
  if (ImGui::Button("X", buttonSize)) values[0] = resetValue;
  ImGui::PopFont();
  ImGui::PopStyleColor(3);

  ImGui::SameLine();
  ImGui::DragFloat("##X", &values[0], 0.1f, 0.0f, 0.0f, "%.2f");
  ImGui::PopItemWidth();
  ImGui::SameLine();

  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
  ImGui::PushFont(boldFont);
  if (ImGui::Button("Y", buttonSize)) values[1] = resetValue;
  ImGui::PopFont();
  ImGui::PopStyleColor(3);

  ImGui::SameLine();
  ImGui::DragFloat("##Y", &values[1], 0.1f, 0.0f, 0.0f, "%.2f");
  ImGui::PopItemWidth();
  ImGui::SameLine();

  ImGui::PopStyleVar();
  ImGui::Columns(1);

  ImGui::PopID();
}