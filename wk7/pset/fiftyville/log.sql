-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find out what tables I can use to find information
.tables

-- What can I find in the crime_scene_reports table?
.schema crime_scene_reports

-- Find the report from July 28, 2023 and on Humphrey Street
SELECT description
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = "Humphrey Street";
-- crime at 10:15; Check Interviews with three people present, all mention the bakery;

-- What can I find ihn the interviews?
.schema interviews

-- Look for names of interviews on 7/28/2023
SELECT name
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28;
-- There are more than just three here

-- Look for names of interviews on 7/28/2023 that mention the bakery
SELECT name
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";
-- Names are Ruth, Eugene, and Raymond

-- Check transcript of all three interviews
SELECT name, transcript
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";
-- Ruth->     Less than 10 min after crime, thief gets in car and leaves in bakery parking lot; Check Bakery Parking Lot cams
-- Eugene->   Eugene knows the thief; Thief withdrew money from ATM on Legget Street
-- Raymond->  Thief made a call <1 min in length after the crime; Thief said they would take first flight out of Fiftyville on 7/29/2023 (day after crime); Accomplice bought ticket after crime (7/28/2023 after 10:15)

-- Check data of Bakery Parking Lot cams
.schema bakery_security_logs

-- Check activity and license plate of bakery cams on 7/28/2023 from 10:05 to 10:25
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 05
AND minute <= 25
AND activity LIKE "exit";
-- License Plates to Check | 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55

-- Does the table people have license plates?
.schema people
-- Yes; also has phone, passport

-- What data is in atm transactions
.schema atm_transactions

-- Check ATM withdrawal on Legget Street on 7/28/2023
SELECT account_number, amount
FROM atm_transactions
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";
-- account_number:amount | 28500762:48, 28296815:20, 76054385:60, 49610011:50, 16153065:80, 25506511:20, 81061156:30, 26013199:35

-- What data does the bank_accounts table have?
.schema bank_accounts
-- account_number, person_id, creation_year

-- What data does the phone_calls table have?
.schema phone_calls
-- caller, reciever, duration, date

-- Check for call on 7/28/2023 and duration of less than 1 minute | caller is thief, reciever is accomplice
SELECT duration, caller, receiver
FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration <= 60;
-- | duration |     caller     |    receiver    |
-- | 51       | (130) 555-0289 | (996) 555-8899 |
-- | 36       | (499) 555-9472 | (892) 555-8872 |
-- | 45       | (367) 555-5533 | (375) 555-8161 |
-- | 60       | (609) 555-5876 | (389) 555-5198 |
-- | 50       | (499) 555-9472 | (717) 555-1342 |
-- | 43       | (286) 555-6063 | (676) 555-6554 |
-- | 49       | (770) 555-1861 | (725) 555-3243 |
-- | 38       | (031) 555-6622 | (910) 555-3251 |
-- | 55       | (826) 555-1652 | (066) 555-9701 |
-- | 54       | (338) 555-6650 | (704) 555-2131 |

-- What data does flights have
.schema flights
-- origin, destination

-- Look for destination of flight ticket on 7/28/2023 departing from Fiftyville
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2023
    AND month = 7
    AND day = 29
    AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = "Fiftyville"
    )
    ORDER BY hour
    LIMIT 1
);
-- Destination City is New York City

-- What data does passengers have?
.schema passengers
-- flight_id, passport_number, seat

-- Check passport numbers and seats of passengers on flight with id of 36
SELECT passport_number, seat
FROM passengers
WHERE flight_id = (
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2023
    AND month = 7
    AND day = 29
    AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = "Fiftyville"
    )
    ORDER BY hour
    LIMIT 1
);
-- | passport_number | seat |
-- | 7214083635      | 2A   |
-- | 1695452385      | 3B   |
-- | 5773159633      | 4A   |
-- | 1540955065      | 5C   |
-- | 8294398571      | 6C   |
-- | 1988161715      | 6D   |
-- | 9878712108      | 7A   |
-- | 8496433585      | 7B   |

-- Check which person was on the flight (passport number), at the bakery (license plate), caller or receiver phone number,
SELECT name
FROM people
WHERE phone_number IN ("(130) 555-0289", "(499) 555-9472", "(367) 555-5533", "(609) 555-5876", "(499) 555-9472", "(286) 555-6063", "(770) 555-1861", "(031) 555-6622", "(826) 555-1652", "(338) 555-6650")
AND passport_number IN (7214083635, 1695452385, 5773159633, 1540955065, 8294398571, 1988161715, 9878712108, 8496433585)
AND license_plate IN ("5P2BI95", "94KL13X", "6P58WS2", "4328GD8", "G412CB7", "L93JTIZ", "322W7JE", "0NTHK55")
AND id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199)
)
;
-- BRUCE is the thief

-- Get phone number of accomplice
SELECT receiver
FROM phone_calls
WHERE caller = (
    SELECT phone_number
    FROM people
    WHERE name = "Bruce"
)
AND year = 2023
AND month = 7
AND day = 28
AND duration < 60
;
-- "(375) 555-8161"

-- Get name of accomplice from their phone number
SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE caller = (
        SELECT phone_number
        FROM people
        WHERE name = "Bruce"
    )
    AND year = 2023
    AND month = 7
    AND day = 28
    AND duration < 60
)
;
-- ROBIN is the accomplice

-- :3 Miau
