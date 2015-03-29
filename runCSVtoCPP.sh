cd "$( dirname "$0" )"
java -jar ./ste15-csv2cpp/dist/CANRecordCodeGenerator.jar -i ./CANMessageRecord/CANMessageRecord.csv -o ./ESLib/include/common

