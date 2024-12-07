#pragma once
#include "Prerrequisitos.h"

/**
 * @brief Servicio de notificaciones para gestionar mensajes del programa asociados a diferentes códigos de error.
 */
class
NotificationService {
public:
  /**
   * Obtiene la instancia única de NotificationService (patrón Singleton).
   */
  static
  NotificationService& getInstance() {
  static NotificationService instance;
  return instance;
  }

  /**
   * Añadir un mensaje a la lista de mensajes de un código de error.
   */
  void
  addMessage(ConsoleErrorType code, const std::string& message) {
  m_programMessages[code].push_back(message);
  }

  /**
   * Agregar un mensaje informativo.
   */
  void
  Log(const std::string& message) {
  ConsoleErrorType code = ConsoleErrorType::INFO;
  m_programMessages[code].push_back(message);
  }

  /**
   * Obtener todos los mensajes de un código de error específico.
   */
  std::string
  getMessage(ConsoleErrorType code) const {
  auto it = m_programMessages.find(code);
  if (it != m_programMessages.end()) {
    std::string combinedMessages;
    for (const auto& message : it->second) {
      combinedMessages += message + "\n";
    }
    return combinedMessages;
  }   
  else {
    return "Message not found";
  }
}

  /**
   * Mostrar todos los mensajes en la consola.
   */
  void
  showAllMessages() const {
  for (const auto& pair : m_programMessages) {
    std::cout << "Code: " << pair.first << " - Messages: " << std::endl;
    for (const auto& message : pair.second) {
      std::cout << "   " << message << std::endl;
    }
  }
}

  /**
   * Guardar todos los mensajes en un archivo.
   */
  void
  saveMessagesToFile(const std::string& filename) const {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo para guardar los mensajes." << std::endl;
    return;
  }

  for (const auto& pair : m_programMessages) {
    file << "Code: " << pair.first << " - Messages: " << std::endl;
    for (const auto& message : pair.second) {
      file << "   " << message << "\n";
    }
  }

  file.close();
  std::cout << "Mensajes guardados en el archivo: " << filename << std::endl;
}

  /**
   * Obtener el mapa completo de notificaciones.
   */
  std::map<ConsoleErrorType, std::vector<std::string>>& getNotifications() {
  return m_programMessages;
 }

private:

  // Mapa para almacenar los mensajes del programa, cada código de error tiene una lista de mensajes.
std::map<ConsoleErrorType, std::vector<std::string>> m_programMessages;

  // Constructor privado para evitar instancias múltiples.
NotificationService() {
}

NotificationService(const NotificationService&) = delete;

NotificationService& operator=(const NotificationService&) = delete;
};
