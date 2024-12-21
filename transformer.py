class Transformer:
    def __init__(self, primary_turns, secondary_turns, efficiency=1.0):
        """
        Initialize the transformer with primary and secondary turns and efficiency.

        :param primary_turns: Number of turns in the primary winding
        :param secondary_turns: Number of turns in the secondary winding
        :param efficiency: Efficiency of the transformer (default is 1.0 for ideal transformer)
        """
        self.primary_turns = primary_turns
        self.secondary_turns = secondary_turns
        self.efficiency = efficiency

    def calculate_output_voltage(self, input_voltage):
        """
        Calculate the output voltage based on the turns ratio and input voltage.

        :param input_voltage: Voltage applied to the primary winding
        :return: Output voltage of the secondary winding
        """
        turns_ratio = self.secondary_turns / self.primary_turns
        return input_voltage * turns_ratio

    def calculate_output_current(self, input_current):
        """
        Calculate the output current based on the turns ratio and input current.

        :param input_current: Current in the primary winding
        :return: Output current of the secondary winding
        """
        turns_ratio = self.primary_turns / self.secondary_turns
        return input_current * turns_ratio * self.efficiency


# Example usage
if __name__ == "__main__":
    # Transformer specifications
    primary_turns = 100  # Number of turns in the primary winding
    secondary_turns = 50  # Number of turns in the secondary winding
    efficiency = 0.98  # Efficiency of the transformer (98%)

    # Input parameters
    input_voltage = 230  # Voltage applied to the primary winding (in volts)
    input_current = 5.0  # Current in the primary winding (in amperes)

    # Create a Transformer instance
    transformer = Transformer(primary_turns, secondary_turns, efficiency)

    # Calculate output voltage and current
    output_voltage = transformer.calculate_output_voltage(input_voltage)
    output_current = transformer.calculate_output_current(input_current)

    # Display results
    print("Transformer Details:")
    print(f"Primary Turns: {primary_turns}")
    print(f"Secondary Turns: {secondary_turns}")
    print(f"Efficiency: {efficiency * 100:.2f}%\n")

    print("Input Values:")
    print(f"Input Voltage: {input_voltage} V")
    print(f"Input Current: {input_current} A\n")

    print("Output Values:")
    print(f"Output Voltage: {output_voltage:.2f} V")
    print(f"Output Current: {output_current:.2f} A")
