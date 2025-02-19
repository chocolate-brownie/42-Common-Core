--- Basic Test Cases ---

./philo 5 800 200 200      # 5 philosophers, die after 800ms, eat 200ms, sleep 200ms
./philo 4 410 200 200      # 4 philosophers with tight timing
./philo 1 800 200 200      # Single philosopher case

--- Edge Cases ---
./philo 2 310 100 100      # 2 philosophers timing edge case
./philo 200 800 200 200    # Many philosophers
./philo 5 800 200 200 7    # With must_eat parameter (7 meals each)

--- Validation Testings ---
./philo                    # No arguments
./philo -5 800 200 200     # Negative number
./philo 5 800 200          # Too few arguments
