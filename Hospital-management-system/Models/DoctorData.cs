namespace Hospital_Management_System.Models
{
    /// <summary>
    /// Represents personal and professional details of a doctor.
    /// </summary>
    public class DoctorData
    {
        private string _name;
        private string _fatherName;
        private string _specialization;
        private string _phone;
        private string _weekdaysAvailability;
        private string _weekendAvailability;

        /// <summary>
        /// Gets or sets the doctor's full name.
        /// </summary>
        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        /// <summary>
        /// Gets or sets the doctor's father's name.
        /// </summary>
        public string FatherName
        {
            get { return _fatherName; }
            set { _fatherName = value; }
        }

        /// <summary>
        /// Gets or sets the doctor's medical specialization.
        /// </summary>
        public string Specialization
        {
            get { return _specialization; }
            set { _specialization = value; }
        }

        /// <summary>
        /// Gets or sets the doctor's phone number.
        /// </summary>
        public string Phone
        {
            get { return _phone; }
            set { _phone = value; }
        }

        /// <summary>
        /// Gets or sets the doctor's availability during weekdays.
        /// </summary>
        public string WeekdaysAvailability
        {
            get { return _weekdaysAvailability; }
            set { _weekdaysAvailability = value; }
        }

        /// <summary>
        /// Gets or sets the doctor's availability during weekends.
        /// </summary>
        public string WeekendAvailability
        {
            get { return _weekendAvailability; }
            set { _weekendAvailability = value; }
        }

        /// <summary>
        /// Initializes a new instance of the DoctorData class with default values.
        /// </summary>
        public DoctorData()
        {
            _name = string.Empty;
            _fatherName = string.Empty;
            _specialization = string.Empty;
            _phone = string.Empty;
            _weekdaysAvailability = string.Empty;
            _weekendAvailability = string.Empty;
        }

        /// <summary>
        /// Initializes a new instance of the DoctorData class with specified details.
        /// </summary>
        /// <param name="name">The doctor's full name.</param>
        /// <param name="fatherName">The doctor's father's name.</param>
        /// <param name="specialization">The doctor's medical specialization.</param>
        /// <param name="phone">The doctor's phone number.</param>
        /// <param name="weekdaysAvailability">The doctor's availability during weekdays.</param>
        /// <param name="weekendAvailability">The doctor's availability during weekends.</param>
        public DoctorData(string name, string fatherName, string specialization, string phone, 
                          string weekdaysAvailability, string weekendAvailability)
        {
            _name = name;
            _fatherName = fatherName;
            _specialization = specialization;
            _phone = phone;
            _weekdaysAvailability = weekdaysAvailability;
            _weekendAvailability = weekendAvailability;
        }
    }
}
