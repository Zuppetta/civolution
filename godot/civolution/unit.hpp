#ifndef UNIT_HPP_
#define UNIT_HPP_

#include <vector>
#include <string>

/*!
 * Defines all the special abilities that a unit can have
 */
enum SpecialAbility {
  SCIENCE, /*! If a unit can make some ground research */
  ARCHAEOLOGY, /*! If a unit can search for a ruin */
  DIPLOMACY, /*! If a unit can start to negotiate with someone else */
  WORKER, /* If a unit can build on a tile */
  TRADING, /* If a unit can trade */
  SETTLER /* If a unit can build a city */
};

/*!
 * Abstract class defining the basic function for a unit.
 */
class Unit {
 public:
  // constructors
  Unit(): aCurrentHp(GetMaxHp()) {}
  /*! Constructor for the inherited classes
   * \param aCurrentHp value of the initial health point
   */
  explicit Unit(int aCurrentHp): aCurrentHp(aCurrentHp) {}
  virtual ~Unit() {}

  // Questions
  /*! Check if the unit has still some Health Point */
  bool IsDead() const;

  // get
  /*! \return Max Health Point */
  virtual int GetMaxHp() const;
  /*! \return Current Health Point */
  virtual std::string GetName() const = 0;
  /*! \return Cost of production */
  virtual int GetProductionCost() const = 0;
  /*! \return All the special abilities */
  virtual std::vector<SpecialAbility> GetSpecialAbilities() const = 0;
  /*! \return Attack value */
  virtual int GetAttack() const = 0;
  /*! \return Attack range */
  virtual int GetRange() const = 0;
  /*! \return Defense */
  virtual int GetDefense() const = 0;
  /*! \return Distance that can travel the unit */
  virtual int GetDisplacement() const = 0;
  /*! \return Current Health Point */
  int GetCurrentHp() const;

  void TakeDamage(float damage);
  // print
  /*! Print the unit in the terminal */
  virtual void PrintTerminal() const;

 private:
  /*! Mean value for the error function in "TakeDamage" */
  static const float MU = 1.0;
  /*! Standard deviation for the error function in "TakeDamage" */
  static const float STD = 1.5;
  /*! Current Health Point of the unit */
  int aCurrentHp;
};

#endif  //  UNIT_HPP_
