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
