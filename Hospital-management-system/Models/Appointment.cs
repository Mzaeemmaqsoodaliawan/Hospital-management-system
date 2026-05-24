namespace Hospital_Management_System.Models
{
    /// <summary>
    /// Represents an appointment between a patient and a doctor.
    /// </summary>
    public class Appointment
    {
        private string _username;
        private string _doctor;
        private string _date;
        private string _time;
        private string _reason;
        private string _status;

        /// <summary>
        /// Gets or sets the patient's username.
        /// </summary>
        public string Username
        {
            get { return _username; }
            set { _username = value; }
        }

        /// <summary>
        /// Gets or sets the doctor's name or ID.
        /// </summary>
        public string Doctor
        {
            get { return _doctor; }
            set { _doctor = value; }
        }

        /// <summary>
        /// Gets or sets the appointment date.
        /// </summary>
        public string Date
        {
            get { return _date; }
            set { _date = value; }
        }

        /// <summary>
        /// Gets or sets the appointment time.
        /// </summary>
        public string Time
        {
            get { return _time; }
            set { _time = value; }
        }

        /// <summary>
        /// Gets or sets the reason for the appointment.
        /// </summary>
        public string Reason
        {
            get { return _reason; }
            set { _reason = value; }
        }

        /// <summary>
        /// Gets or sets the appointment status (e.g., Scheduled, Completed, Cancelled).
        /// </summary>
        public string Status
        {
            get { return _status; }
            set { _status = value; }
        }

        /// <summary>
        /// Initializes a new instance of the Appointment class with default values.
        /// </summary>
        public Appointment()
        {
            _username = string.Empty;
            _doctor = string.Empty;
            _date = string.Empty;
            _time = string.Empty;
            _reason = string.Empty;
            _status = string.Empty;
        }

        /// <summary>
        /// Initializes a new instance of the Appointment class with specified details.
        /// </summary>
        /// <param name="username">The patient's username.</param>
        /// <param name="doctor">The doctor's name or ID.</param>
        /// <param name="date">The appointment date.</param>
        /// <param name="time">The appointment time.</param>
        /// <param name="reason">The reason for the appointment.</param>
        /// <param name="status">The appointment status.</param>
        public Appointment(string username, string doctor, string date, string time, string reason, string status)
        {
            _username = username;
            _doctor = doctor;
            _date = date;
            _time = time;
            _reason = reason;
            _status = status;
        }
    }
}
