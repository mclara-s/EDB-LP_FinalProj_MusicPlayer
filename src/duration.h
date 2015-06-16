#ifndef DURATION_H
#define DURATION_H

#include <utility>
#include <QString>

/**
 * @brief Duração de uma música ou playlist.
 *
 * A classe Duration provê funcionalidades relacionadas à duração de uma música
 * ou playlist.
 */
class Duration
{
public:
  /**
   * Initializa um objeto Duration com o tempo total em segundos.
   *
   * @param s Duração total, em segundos.
   */
  Duration(int s);

  /**
   * Retorna o número de segundos dessa Duration.
   *
   * @returns Número de segundos.
   */
  int getSeconds();

  /**
   * Retorna o número de minutos dessa Duration.
   *
   * @returns Número de minutos.
   */
  int getMinutes();

  /**
   * Retorna o tempo total em segundos.
   *
   * returns O tempo total, em segundos.
   */
  int getTotalSeconds();

  /**
   * Retorna uma representação em string da duração, no formato mm:ss.
   *
   * @returns A duração formatada como string.
   */
  QString toString();

  /**
   * Retorna true se o tempo em segundos de other é o mesmo.
   */
  bool operator==(const Duration& other) const { return this->seconds == other.seconds; }

  /**
   * Retornar true se o tempo em segundos de other é diferente.
   */
  bool operator!=(const Duration& other) const { return !(this->operator==(other)); }

  /**
   * Retorna true se o tempo em segundos de other é maior.
   */
  bool operator<(const Duration& other) const { return this->seconds < other.seconds; }

  /**
   * Retornar true se o tempo em segundos de other é menor.
   */
  bool operator>(const Duration& other) { return other.operator<(*this); }

private:
  int seconds;
};
#endif